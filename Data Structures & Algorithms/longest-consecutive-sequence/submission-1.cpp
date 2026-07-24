class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int current = 1;
        int ans = 1;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            else if (nums[i] + 1 == nums[i + 1]) {
                current++;
                ans = max(ans, current);
            }
            else {
                current = 1;
            }
        }

        return ans;
    }
};