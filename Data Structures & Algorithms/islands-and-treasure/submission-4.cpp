class Solution {
    # define F first
    # define S second
 using state=pair<int,int>;
    queue<state> q;
    vector<vector<int>> dis;
    vector<vector<int>>  vis;

public:
    bool check(int x,int y,int n,int m,vector<vector<int>>& grid){
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]!=-1 ){
            return true;
        }
        return false;
    }
    vector<state> neigh(int x,int y,int n,int m,vector<vector<int>>& grid){
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        vector<state> ans;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=dy[i]+y;
            if(check(xx,yy,n,m,grid)){
                ans.push_back({xx,yy});
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int n,int m){
        while(!q.empty()){
            state curr=q.front();
            q.pop();
            for(auto v:neigh(curr.F,curr.S,n,m,grid)){
                if(!vis[v.F][v.S]){
                    vis[v.F][v.S]=1;
                    dis[v.F][v.S]=dis[curr.F][curr.S]+1;
                    q.push({v.F,v.S});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vis.assign(n,vector<int>(m,0));
          dis.assign(n, vector<int>(m,2147483647));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;;
                    dis[i][j]=0;
                }
            }
        }
        dfs(grid,n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2147483647)
                {
                    grid[i][j]=dis[i][j];
                }
            }
        }
    }
};
