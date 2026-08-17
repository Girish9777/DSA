class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
            vector<string>ans(n,string(n,'.'));
            vector<int> store(n,-1);
            rec(res,0,n,ans,store);
            return res;

    }
    void rec(vector<vector<string>>& res,int level,int n,vector<string>& ans,vector<int>& store){
        if(level==n){
            res.push_back(ans);
            return ;
        }
        // choice 
        // if place
        for(int i=0;i<n;i++){
            if(check(ans,i,level,store)){
                ans[level][i]='Q';
                store[level]=i;
                rec(res,level+1,n,ans,store);
                store[level]=-1;
                ans[level][i]='.';
            }
        }
        
    }
    bool check(vector<string>& ans,int col,int level,vector<int> store){
        
        for(int i=0;i<level;i++){
            int pc=store[i];
            if(col==pc || abs(col-pc)==abs(i-level) ){
                return false;
            }
            
        }
        return true;
    }
};
