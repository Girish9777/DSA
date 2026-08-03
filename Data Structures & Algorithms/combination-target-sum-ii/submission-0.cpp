class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> output;
        vector<int> ans;
        rec(candidates,output,ans,target,0,0);
        return output;
    }
    void rec(vector<int>& candidates,vector<vector<int>>& output,vector<int> ans,int target,int sum,int index){
        
        if(sum==target){
            output.push_back(ans);
            return ;
        }
        if(index==candidates.size())return;
        
        if(candidates[index]+sum<=target){
            sum+=candidates[index];
            ans.push_back(candidates[index]);
            rec(candidates,output,ans,target,sum,index+1);
            sum-=candidates[index];
            ans.pop_back();
        }
        int i=index+1;
    while(i<candidates.size() && candidates[i]==candidates[i-1] ){
        i++;
    }
         rec(candidates,output,ans,target,sum,i);
    }
};
