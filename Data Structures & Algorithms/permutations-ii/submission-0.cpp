class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> ans;
        map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        rec(nums.size(), output, ans, mp);
        return output;
    }

    void rec(int n,
             vector<vector<int>>& output,
             vector<int>& ans,
             map<int, int>& mp) {

        // Base Case
        if (ans.size() == n) {
            output.push_back(ans);
            return;
        }

        // Choice
        for (auto& x : mp) {
            if (x.second > 0) {

                // Move
                ans.push_back(x.first);
                x.second--;

                rec(n, output, ans, mp);

                // Backtrack / Undo
                x.second++;
                ans.pop_back();
            }
        }
    }
};