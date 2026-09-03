class Solution {
    #define F first
    #define S second
    using state=pair<int,int>;
    
public:
    vector<vector<pair<int,int>>> components;
    vector<vector<int>> vis;
    int n,m;
    bool check(int xx,int yy,vector<vector<int>>& grid){
        if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]!=0){
            return true;
        }
        return false;
    }
    vector<state> neigh(int x,int y,vector<vector<int>>& grid){
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        vector<state> ans;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=dy[i]+y;
            if(check(xx,yy,grid)){
                ans.push_back({xx,yy});
            }
        }
        return ans;
    }

    void dfs(int i,int j,vector<vector<int>>& grid,int comp_no){
        vis[i][j]=1;
        components[comp_no].push_back({i,j});
        for(auto v:neigh(i,j,grid)){
            if(!vis[v.F][v.S]){
                dfs(v.F,v.S,grid,comp_no);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        components.resize(n * m + 1);
        vis.assign(n,vector<int>(m,0));
        int comp_no=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    comp_no++;
                    dfs(i,j,grid,comp_no);
                }
            }
        }
        int ans=0;

        for(auto v:components){
            int size=v.size();
            ans=max(ans,size);
        }
        return ans;
    }
};
