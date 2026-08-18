class Solution {
public:
    void rec(vector<vector<int>>& ans,vector<int>& res,vector<int>& nums,int idx){


        if(idx==nums.size()){
            ans.push_back(res);
            return;
        }

        // choice to take or ot
        res.push_back(nums[idx]);
        rec(ans,res,nums,idx+1);
        res.pop_back();

        // not to ktake 
        int next=idx+1;
        while(next<nums.size() && nums[next]==nums[idx]){
            next++;
        }
        rec(ans,res,nums,next);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;sort(nums.begin(),nums.end());
        vector<int> res;
        rec(ans,res,nums,0);return ans;
    }
};
