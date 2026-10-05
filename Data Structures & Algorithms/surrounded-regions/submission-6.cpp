class Solution {
    #define F first
    #define S second
    using state=pair<int,int>;
    
public:
int n,m;
    vector<vector<int>> vis;
    vector<vector<pair<int,int>>> components;
    bool check(int i,int j,vector<vector<char>>& board){
        if(i>=0 && i<n && j>=0 && j<m && !vis[i][j] && board[i][j]=='O')
        {
            return true;
        }
        return false;
    }
    vector<state> neight(int i,int j,vector<vector<char>>& board){
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        vector<state> ans;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(check(x,y,board)){
                ans.push_back({x,y});
            }
        }
        return ans;
    }


    void dfs(int i,int j,int comp_no,vector<vector<char>>& board){
    components[comp_no].push_back({i,j});
    vis[i][j]=1;
    for(auto v:neight(i,j,board)){
        if(!vis[v.F][v.S]){
            dfs(v.F,v.S,comp_no,board);
        }
    }

    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        int comp_no=0;
     m=board[0].size();
        vis.assign(n,vector<int> (m,0));
        components.resize(n*m+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    comp_no++;
                    dfs(i,j,comp_no,board);
                }
                
            }
        }
        vector<int> temp(comp_no+1,0);
        bool found=false;
     for(int k=1;k<=comp_no;k++){
        for(auto v:components[k]){
            int i=v.F;
            int j=v.S;
            if(i==0 || j==0 || i==n-1 || j==m-1)
            {
                temp[k]=1;
                break;
            }
        }
     }
      for(int k=1;k<=comp_no;k++){
        if(temp[k]==0){
            for(auto v:components[k]){
                int i=v.F;
                int j=v.S;
                board[i][j]='X';
                            }
        }
        
     }

    }
};
