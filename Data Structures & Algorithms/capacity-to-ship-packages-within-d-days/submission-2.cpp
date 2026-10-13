class Solution {
public:
    bool check(int mid, vector<int>& weights, int days) {
        int total = 0;
        int count = 1;  // Corrected: First day is already counted

        for (int i = 0; i < weights.size(); i++) {
            if (total + weights[i] <= mid) {
                total += weights[i];
            }
            else {
                count++;
                total = weights[i];
            }
        }

        if (count <= days) return true;
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int e = 0;

        for (int i = 0; i < weights.size(); i++) {
            s = max(s, weights[i]);
            e += weights[i];
        }

        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (check(mid, weights, days)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};