class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int,int> mp;
      multiset<pair<int,int>> freq_order;//sorting freq_wise
      for(int i=0;i<nums.size();i++){
        if(freq_order.find(make_pair(mp[nums[i]],-nums[i]))!=freq_order.end()){
            freq_order.erase(freq_order.find(make_pair(mp[nums[i]],-nums[i])));
        }
        mp[nums[i]]++;
        freq_order.insert(make_pair(mp[nums[i]],-nums[i]));
      
      }
      vector<int> ans;
      int count=k;
      while(count--){
        ans.push_back(-(freq_order.rbegin()->second));
        freq_order.erase(prev(freq_order.end()));
      }
      return ans;
    }
};
