class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> mp;

        for (int i = 0; i < position.size(); i++) {
            double time =
                (double)(target - position[i]) / speed[i];

            mp.push_back({position[i], time});
        }

        // Position ke according ascending order
        sort(mp.begin(), mp.end());

        double prev = 0;
        int fleet = 0;

        // Target ke nearest car se start
        for (int i = (int)mp.size() - 1; i >= 0; i--) {
            double currtime = mp[i].second;

            if (currtime > prev) {
                fleet++;
                prev = currtime;
            }
        }

        return fleet;
    }
};