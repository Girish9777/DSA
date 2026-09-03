class Solution {
    #define F first
    #define S second

    using state = pair<int,int>;

public:

    vector<vector<int>> vis, dis;
    queue<state> q;

    bool check(int xx, int yy, int n, int m, vector<vector<int>>& grid){

        // ERROR: tumne y < m likha tha
        // correct: yy < m

        // ERROR: tum grid[xx][yy] == 0 check kar rahe the
        // 0 treasure hai, hume INF land par move karna hai

        if(xx >= 0 && yy >= 0 && xx < n && yy < m
           && grid[xx][yy] == 2147483647){

            return true;
        }

        return false;
    }

    vector<state> neigh(int x, int y, int n, int m, vector<vector<int>>& grid){

        vector<state> ans;

        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};

        for(int i = 0; i < 4; i++){

            int xx = x + dx[i];
            int yy = y + dy[i];

            if(check(xx, yy, n, m, grid)){
                ans.push_back({xx,yy});
            }
        }

        return ans;
    }

    void bfs(int n, int m, vector<vector<int>>& grid){

        // ERROR: bfs me x,y ki zarurat nahi thi
        // kyunki saare source already queue me push hain

        while(!q.empty()){

            state curr = q.front();
            q.pop();

            for(auto v : neigh(curr.F, curr.S, n, m, grid)){

                if(!vis[v.F][v.S]){

                    vis[v.F][v.S] = 1;

                    dis[v.F][v.S] =
                        dis[curr.F][curr.S] + 1;

                    q.push({v.F, v.S});
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vis.assign(n, vector<int>(m, 0));
        dis.assign(n, vector<int>(m, 1e9));

        // Step 1:
        // saare treasures ko queue me daalo

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                // ERROR: tum grid[i][j] == 1 kar rahe the
                // treasure ki value 0 hoti hai

                if(grid[i][j] == 0){

                    q.push({i,j});

                    vis[i][j] = 1;
                    dis[i][j] = 0;
                }
            }
        }

        // ERROR: tum bfs(xx,yy,n,m,grid) kar rahe the
        // xx aur yy yahan defined bhi nahi the
        bfs(n, m, grid);

        // Step 2:
        // calculated distance grid me daal do

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                // walls ko change nahi karna
                if(grid[i][j] != -1){

                    // ERROR: tum == use kar rahe the
                    // assignment ke liye = use hota hai

                    if(dis[i][j] != 1e9){
                        grid[i][j] = dis[i][j];
                    }
                }
            }
        }
    }
};