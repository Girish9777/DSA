class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr="";
        rec(n,ans,curr);
        return ans;
    }
    void rec(int n,vector<string>& ans,string curr){
        if(curr.length()==2*n){
            if(check(curr)){
                ans.push_back(curr);
                
            }return;
            //basecase
        }

        // take or not take;
        curr+='(';
        rec(n,ans,curr);;
        curr.pop_back();
        curr+=')';
        rec(n,ans,curr);
        curr.pop_back();
    }
    bool check(string curr){
        int depth=0;
        for(int i=0;i<curr.length();i++){
            if(curr[i]=='('){
                depth++;
            }else{
                depth--;
            }
            if(depth<0){
                return false;
            }
        }
        if(depth==0)return true;
        return false;
    }
};
