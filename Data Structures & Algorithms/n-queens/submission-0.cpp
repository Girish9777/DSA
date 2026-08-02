class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> queens(n, string(n, '.'));
        vector<int> store(n,-1);

        // vector<vector<string>> q(n,('.',n));
        rec(output,queens,store,n,0);
        return output;
    }
    void rec(vector<vector<string>>& output,
             vector<string>& queens,
             vector<int>& store,
             int n,int level) {
        // base case means level if level ==n it means all quesms are palceed 
        if(level==n){
            output.push_back(queens);
            return ;

        } // choice to take or not 
        for(int i=0;i<n;i++){
            if(check(level,i,store)){
                queens[level][i]='Q';
                store[level]=i;
                rec(output,queens,store,n,level+1);
                queens[level][i]='.';
                store[level]=-1;
            }
        }
    }
    bool check(int row,int col,vector<int> store){
        for(int pr=0;pr<row;pr++){
            int pc=store[pr];
            // attacking conditiones
            if(pc==col || abs(pc-col)==abs(pr-row)){
                return false;
            }
        }
        return true;
    }
};
