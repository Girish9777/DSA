class Solution {
    using state=pair<int,int>;
public:
    vector<vector<int>> vis;int n;
        int m;
    bool check(int xx,int yy,vector<vector<char>>& board){
        if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]!='X'){
            return true;
        }
        return false;
    }
    vector<state> neigh(int x,int y,vector<vector<char>>& board)
    {
        vector<state> ans;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {   int xx=x+dx[i];
            int yy=dy[i]+y;
            if(check(xx,yy,board)){
                ans.push_back({xx,yy});
            }
        }
        return ans;
    }
    void dfs(int i,int j,vector<vector<char>>& board)
    {
        vis[i][j]=1;
        for(auto v:neigh(i,j,board)){
            if(!vis[v.first][v.second]){
                dfs(v.first,v.second,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
         n=board.size();
        m=board[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1 )&& board[i][j]=='O'){
                    if(!vis[i][j])
                    {
                        dfs(i,j,board);
                    }
                }
            }
        }


          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
             }
            }
        }

    }
};
