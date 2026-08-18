class Solution {
public:
    void rec(vector<int>& nums,vector<vector<int>>& ans,vector<int>& res,int idx){
        if(idx==nums.size()){
        ans.push_back(res);
        return ;
        }
        // choidce 
    res.push_back(nums[idx]);
         rec(nums,ans,res,idx+1);
        res.pop_back();
         int next=idx+1;
         while(next<nums.size() && nums[next]==nums[idx]){
            next++;
         }
         rec (nums,ans,res,next);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;sort(nums.begin(),nums.end());
        rec(nums,ans,res,0);
        return ans;
    }
};
