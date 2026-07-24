class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;int anss=0;
        for(int i=0;i<nums.size();i++){
                anss=target-nums[i];
                if(mp.find(anss)!=mp.end()){
                    ans.push_back(min(mp[anss],i));
                    ans.push_back(max(mp[anss],i));
                }else{
                    mp[nums[i]]=i;
                }
        }return ans;
    }
};
