
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        // Total cards must be divisible into equal-sized groups.
        if (hand.size() % groupSize != 0) {
            return false;
        }

        // Store the frequency of each card.
        vector<int> mp(1001, 0);
        int maxi = 0;

        for (int i = 0; i < hand.size(); i++) {
            mp[hand[i]]++;
            maxi = max(maxi, hand[i]);
        }

        int count = 0;
        int prev = 0;

        while (true) {

            // Find the smallest card that is still available.
            int start = -1;

            for (int i = 0; i <= maxi; i++) {
                if (mp[i] > 0) {
                    start = i;
                    break;
                }
            }

            // No cards remain, so all groups were formed.
            if (start == -1) {
                return true;
            }

            // Start forming a new group.
            count = 0;
            prev = start;

            for (int i = start; i <= maxi; i++) {

                // The required consecutive card is unavailable.
                if (mp[i] == 0) {
                    return false;
                }

                if (count == 0) {
                    // Select the first card of this group.
                    prev = i;
                    count++;
                    mp[i]--;
                }
                else if (i == prev + 1) {
                    // Select the next consecutive card.
                    prev = i;
                    count++;
                    mp[i]--;
                }
                else {
                    return false;
                }

                // The current group is complete.
                if (count == groupSize) {
                    break;
                }
            }

            // The loop may end before the group is complete.
            if (count != groupSize) {
                return false;
            }

            // The next while-loop iteration starts another group.
        }
    }
};
