class Solution {
public:
    void rec(vector<int>& nums,int idx,vector<vector<int>>& ans,vector<int>& res){
        if(idx==nums.size()){
        ans.push_back(res);
        return ;
        }
        // to take or not
        res.push_back(nums[idx]);
        rec(nums,idx+1,ans,res);
        res.pop_back();

        // not to take
        rec(nums,idx+1,ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int > res;
        rec(nums,0,ans,res);
        return ans;
    }
};
