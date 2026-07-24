class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back({nums[i],i});
        }
        int i=0;
        int r=nums.size()-1;
        sort(ans.begin(),ans.end());
        while(i<r){
            int sum=ans[i].first+ans[r].first;
            if(sum==target){
                return {min(ans[i].second,ans[r].second),
                        max(ans[i].second,ans[r].second)
                };
            }
            else if(sum<target){
                i++;
            }else{
                r--;
            }
        }
        return {};
    }
};
