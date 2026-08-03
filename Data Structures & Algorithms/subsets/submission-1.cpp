class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> ans;
        rec(nums,output,ans,0);
        return output;
    }
    void rec(vector<int>&nums,vector<vector<int>>& output,vector<int>& ans,int idx){
        if(idx==nums.size())
        {
            output.push_back(ans);
            return;
        }

        // choice is to incclude or exclude
        ans.push_back(nums[idx]);
        rec(nums,output,ans,idx+1);
        ans.pop_back();

        rec(nums,output,ans,idx+1);
    }
};
