class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // Corrected: reference declare nahi karna, actual vector banana hai
        vector<vector<int>> output;

        vector<int> ans;
        rec(nums, output, ans, 0);

        return output;
    }

    void rec(vector<int>& nums,
             vector<vector<int>>& output,
             vector<int>& ans,
             int idx) {

        // Corrected: [ ] ki jagah { } braces
        if (idx == nums.size()) {
            output.push_back(ans);
            return;
        }

        // Choice 1: Take current element
        ans.push_back(nums[idx]);
        rec(nums, output, ans, idx + 1);
        ans.pop_back();

        // Choice 2: Not take current element
        int i = idx + 1;

        // Corrected: n declared nahi tha, nums.size() use kiya
        while (i < nums.size() && nums[i] == nums[i - 1]) {
            i++;
        }
        idx=i;
        // Duplicate values skip karke recursion
        rec(nums, output, ans, idx);
    }
};