class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans=nums[0];
        int lo=0;
        int e=nums.size()-1;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(nums,mid)){
               
                lo=mid+1;
            }
            else
            {ans=nums[mid];               hi=mid-1;
            }
        }
        return ans;
    }bool check(vector<int>& nums,int mid){
        int e=nums.size()-1;
        if(nums[mid]>nums[e])return true;
        return false;
    }
};
