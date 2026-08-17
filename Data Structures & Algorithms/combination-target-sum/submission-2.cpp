class Solution {
public:
    void rec(vector<int>& nums,int target,vector<vector<int>>& res,vector<int>& ans,int sum,int i)
    {    if(sum>target || i==nums.size()){
        return ;
    }
        if(sum==target){
            res.push_back(ans);
            return ;
        }
        // choice 
        sum+=nums[i];
        ans.push_back(nums[i]);
        rec(nums,target,res,ans,sum,i);
        ans.pop_back();
       sum-=nums[i];

        rec(nums,target,res,ans,sum,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        int sum=0;
        rec(nums,target,res,ans,sum,0);
        return res;
    }
};
