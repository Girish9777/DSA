class Solution {
    using state=pair<int,int>;
public:
    vector<vector<int>> dis,vis;
    bool check(int x,int y,int n,int m,vector<vector<char>>& grid){
        if(x>=0 && y>=0 &&  x<n && y<m && grid[x][y]=='1'){
            return true;
        }
        return false;
    }
    vector<state> neighbours(int x,int y,int n,int m,vector<vector<char>>& grid){
        vector<state> ans;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int xx=dx[i]+x;
            int yy=dy[i]+y;
            if(check(xx,yy,n,m,grid)){
                ans.push_back({xx,yy});
            }
        }
        return ans;
    }

    void dfs(int i ,int j,int &comp_no,int n,int m,vector<vector<char>>& grid){
        vis[i][j]=1;
        for(auto v:neighbours(i,j,n,m,grid)){
            if(!vis[v.first][v.second]){
                dfs(v.first,v.second,comp_no,n,m,grid);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
dis.assign(n, vector<int>(m, 1e9));
vis.assign(n, vector<int>(m, 0));
    int comp_no=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]!='0'){
                    comp_no++;
                    dfs(i,j,comp_no,n,m,grid);
                }
            }
        }
        return comp_no;
    }
};
