class Solution {
public:
    pair<int,bool> check(int mid, vector<int>& nums, int k) {
        int total = 0;
        int count = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(total + nums[i] <= mid) {
                total += nums[i];
            }
            else {
                total = nums[i];
                count++;
            }
        }

        bool found = false;

        if(count > k) {
            found = true;  // More than k subarrays needed
        }

        return {count, found};
    }

    int splitArray(vector<int>& nums, int k) {
        int s = 0;
        int e = 0;

        for(int i = 0; i < nums.size(); i++) {
            s = max(s, nums[i]);
            e += nums[i];
        }

        int ans = 0;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            pair<int,bool> res = check(mid, nums, k);

            int count = res.first;
            bool found = res.second;

            // ERROR 1: Removed if(count == k)
            // Any count <= k is feasible
            if(!found) {
                ans = mid;
                e = mid - 1;
            }
            else {
                // ERROR 2: If count > k,
                // increase allowed maximum sum
                s = mid + 1;
            }
        }

        return ans;
    }
};