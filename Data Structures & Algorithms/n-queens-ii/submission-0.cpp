class Solution {
public:
    int totalNQueens(int n) {
        int ans=0;
        vector<int> queens(n,-1);
        rec(n,0,ans,queens);
        return ans;
    }
   void rec(int n,int level,int& ans,vector<int>& queens){
        if(level==n){
            ans+=1;
            return ;
        }
        for(int i=0;i<n;i++){
            if(check(queens,level,i)){
                    queens[level]=i;
                    rec(n,level+1,ans,queens);
                    queens[level]=-1;
            }
        }
    }
    bool check(vector<int>& queens,int row,int col){
        for(int pr=0;pr<row;pr++){
            int pc=queens[pr];
            if(pc==col || abs(pr-row)==abs(pc-col)){
                return false;
            }
        }
        return true;
    }
};