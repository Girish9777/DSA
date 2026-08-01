class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        vector<int> ans;
        rec(nums,output,ans,target,0,0);
        return output;
    }
    void rec(vector<int>& nums,vector<vector<int>>& output,vector<int>& ans,int target,int idx,int sum){
        if(idx==nums.size())return;
        if(sum==target){
            output.push_back(ans);
            return ;
        }

        // choice 
        if(check(idx,sum,target,nums)){
            ans.push_back(nums[idx]);
            rec(nums,output,ans,target,idx,sum+nums[idx]);
            ans.pop_back();
        }
        rec(nums,output,ans,target,idx+1,sum);
    }
    bool check(int index,int sum,int target,vector<int>& nums){
        if(nums[index]+sum<=target)return true;


        else return false;
    }
};
