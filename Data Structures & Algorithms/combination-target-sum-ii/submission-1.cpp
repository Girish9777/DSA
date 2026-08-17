class Solution {
public:
    void rec(vector<int>& candidates,vector<vector<int>>& res,vector<int> ans,int sum,int target,int i){
        if(sum==target){
            res.push_back(ans);
            return ;
        }
        if(sum>target || i>=candidates.size())return;

        // to take or not
        sum+=candidates[i];
        ans.push_back(candidates[i]);
        rec(candidates,res,ans,sum,target,i+1);
        sum-=candidates[i];
        ans.pop_back();

                int next=i+1;
                while(next<candidates.size() && candidates[next]==candidates[i]){
                    next++;
                }
               rec(candidates,res,ans,sum,target,next); 


        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;sort(candidates.begin(),candidates.end());
        int sum=0;
        rec(candidates,res,ans,sum,target,0);
        return res;
    }
};
