class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        multiset<pair<int,int>> freq_order; // sorting by frewq
        for(int i=0;i<nums.size();i++){
            if(freq_order.find(make_pair(mp[nums[i]],-nums[i])) != freq_order.end()){
                freq_order.erase(make_pair(mp[nums[i]],-nums[i]));
            }
            mp[nums[i]]++;
            freq_order.insert(make_pair(mp[nums[i]],-nums[i]));
        }
        int count=k;
        while(count--){
            ans.push_back(-(freq_order.rbegin()->second));
            auto it=freq_order.end();
            it--;
            freq_order.erase(it);
        }return ans;
    }
};
