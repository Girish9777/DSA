class Solution { 
    using state = pair<int,int>; 

public:  

    queue<pair<int,int>> q; 
    vector<vector<int>> vis, dis;
    int n, m; 
    int ans = 0; 

    bool check(int xx, int yy, vector<vector<int>>& grid){ 

        // ERROR FIX:
        // pehle: yy<m ki jagah y<m likha tha
        if(xx >= 0 && yy >= 0 && xx < n && yy < m && grid[xx][yy] == 1){ 
            return true; 
        } 

        return false; 
    } 


    vector<state> neigh(int x, int y, vector<vector<int>>& grid){

        int dy[4] = {-1,1,0,0}; 
        int dx[4] = {0,0,-1,1}; 

        vector<state> ans; 

        for(int i = 0; i < 4; i++){ 

            int xx = dx[i] + x; 
            int yy = dy[i] + y; 

            if(check(xx, yy, grid)){ 
                ans.push_back({xx,yy}); 
            } 
        } 

        return ans; 
    } 


    void bfs(vector<vector<int>>& grid){ 

        while(!q.empty()){ 

            int x = q.front().first; 
            int y = q.front().second; 

            // ERROR FIX:
            // pehle q.pop() missing tha
            q.pop(); 


           

         


            for(auto v : neigh(x,y,grid)){ 

                if(!vis[v.first][v.second]){ 
                       vis[v.first][v.second] = 1; 

                    // neighbour rotten hone ka time
                    dis[v.first][v.second] = dis[x][y] + 1; 

                    ans = max(ans, dis[v.first][v.second]); 


                    // ERROR FIX:
                    // pehle:
                    // q.push({x,y});
                    //
                    // current node ko dobara push nahi karna
                    // neighbour ko push karna hai
                    q.push({v.first,v.second}); 
                } 
            } 
        } 
    } 


    int orangesRotting(vector<vector<int>>& grid) { 

        n = grid.size(); 
        m = grid[0].size(); 

        vis.assign(n, vector<int>(m,0)); 


        // ERROR FIX:
        // pehle tumne dobara vis.assign(...) kar diya tha
        //
        // vis.assign(n,vector<int>(m,1e9)); ❌
        //
        // actually dis initialise karna tha
        dis.assign(n, vector<int>(m,1e9)); 


        // MULTI SOURCE BFS
        // saare initially rotten fruits ko queue mein daalo
        for(int i = 0; i < n; i++){ 

            for(int j = 0; j < m; j++){ 

                if(grid[i][j] == 2){ 
                    vis[i][j]=1;
                    q.push({i,j}); 

                    // rotten fruit initially time 0 par rotten hai
                    dis[i][j] = 0; 
                } 
            } 
        } 


        bfs(grid); 


        // check karo koi fresh fruit unreachable toh nahi reh gaya
        for(int i = 0; i < n; i++){ 

            for(int j = 0; j < m; j++){ 


                // ERROR FIX:
                // pehle:
                // dis[i][j] = 1e9; ❌
                //
                // assignment nahi comparison karna hai
                //
                // aur condition ke andar ; bhi hata diya
                if(grid[i][j] == 1 && dis[i][j] == 1e9){ 
                    return -1; 
                } 
            } 
        } 


        return ans; 
    } 
};