class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int,int> mp;int ans=0;
       if(k==0){
        return false;
       }
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]=-1;
       }
       for(int i=0;i<nums.size();i++)
       {
        if(mp[nums[i]]==-1){
            mp[nums[i]]=i;
        }
        else{
            ans=abs(mp[nums[i]]-i);
            if(ans<=k)return true;
            
            mp[nums[i]]=i;
        }
       }
       
       return false;
    }
};