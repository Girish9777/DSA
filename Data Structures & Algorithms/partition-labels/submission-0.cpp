
class Solution {
public:
    vector<int> partitionLabels(string s) {
        set<char> st;
        map<char, int> mp;

        // Count frequency of every character.
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        vector<int> ans;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            count++;

            // Current character has been processed once.
            mp[s[i]]--;

            if (mp[s[i]] > 0) {
                st.insert(s[i]);
            } else {
                st.erase(s[i]);
            }

            // If no character has remaining occurrences,
            // the current partition is complete.
            if (st.empty()) {
                ans.push_back(count);
                count = 0;
            }
        }

        return ans;
    }
};
