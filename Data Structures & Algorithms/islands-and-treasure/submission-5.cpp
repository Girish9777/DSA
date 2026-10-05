class Solution {
    #define F first
    #define S second
    using state=pair<int,int>;
    bool check(int i,int j,vector<vector<int>>& grid)
    {
         int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]!=0 && grid[i][j]!=-1){
            return true;
        }
        return false;
    }
    vector<state>  neigh(int i,int j,vector<vector<int>>& grid){
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        vector<state> ans;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(check(x,y,grid)){
                ans.push_back({x,y});
            }
        }
        return ans;
    }
    void bfs(queue<state> q,vector<vector<int>>& grid){
        while(!q.empty())
        {
            state curr=q.front();
            q.pop();
            int x=curr.F;
            int y=curr.S;
            for(auto v:neigh(x,y,grid)){
                if(dis[v.F][v.S]>dis[x][y]+1){
                    dis[v.F][v.S]=dis[x][y]+1;
                    q.push({v.F,v.S});
                    vis[v.F][v.S]=1;
                }
            }
        }
    }
public:
    vector<vector<int>> vis,dis;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<state> q;
        int n=grid.size();
        int m=grid[0].size();
        dis.assign(n,vector<int>(m,1e9));
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                    dis[i][j]=0;
                }
            }
        }
        bfs(q,grid);
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(dis[i][j]!=1e9 || 0){
                grid[i][j]=dis[i][j];
              }
            }
        }
        
    }
};
