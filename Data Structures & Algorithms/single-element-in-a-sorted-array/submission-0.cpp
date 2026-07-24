class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=1;
        int hi=n-2;
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-2]!=nums[n-1])return nums[n-1];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            else if(mid%2==1){
                if(nums[mid-1]==nums[mid]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            
        }return -1;
    }
};