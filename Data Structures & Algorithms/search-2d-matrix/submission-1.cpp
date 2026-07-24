class Solution {

public:
    // ❌ Error 1:
    // check() bool return kar raha hai.
    // Binary Search me hume current value chahiye, true/false nahi.

    int check(int mid, vector<vector<int>>& matrix) {
        int row = mid / matrix[0].size();
        int col = mid % matrix[0].size();

        return matrix[row][col];   // ✅ Return the current element
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();      // rows
        int m = matrix[0].size();   // columns

        // ❌ Error 2:
        // lo = 1 se first element skip ho jayega.
        int lo = 0;

        int hi = n * m - 1;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            int val = check(mid, matrix);

            // ❌ Error 3:
            // check(mid) >= target
            // check() bool return kar raha tha.
            // Ab current value compare karni hai.

            if (val == target) {
                return true;
            }

            else if (val < target) {
                lo = mid + 1;
            }

            else {
                hi = mid - 1;
            }
        }

        return false;
    }
};