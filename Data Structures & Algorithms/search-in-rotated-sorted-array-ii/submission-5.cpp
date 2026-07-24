class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return true;

            if (lo < hi && nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                lo++;
                hi--;
            }
            else if (nums[lo] <= nums[mid]) {   // Left half is sorted

                // ❌ ERROR:
                // Tum nums[hi] se compare kar rahe ho.
                // Left sorted hai to target sirf nums[lo] aur nums[mid] ke beech hi ho sakta hai.

                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            else {                              // Right half is sorted

                // ❌ ERROR:
                // Tum nums[mid] ko bhi include kar rahe ho (<=),
                // lekin nums[mid] target hota to upar return ho chuka hota.
                // Isliye comparison strict (<) hoga.

                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        return false;
    }
};