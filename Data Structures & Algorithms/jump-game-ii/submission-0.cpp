#include<cstring>
class Solution {
public:
    int dp[1003];

    int rec(int level, vector<int>& nums) {
        if (level == nums.size() - 1) {
            return 0;
        }

        if (level >= nums.size()) {
            return 1e9;
        }

        if (dp[level] != -1) {
            return dp[level];
        }

        int ans = 1e9;

        for (int i = 1; i <= nums[level]; i++) {
            ans=min(ans,rec(level+i,nums)+1);
        }

        return dp[level] = ans;
    }

    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, nums);
    }
};