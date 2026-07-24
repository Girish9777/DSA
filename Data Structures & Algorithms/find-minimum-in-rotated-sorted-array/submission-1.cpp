class Solution {
public:
 
    int findMin(vector<int> &nums) {
        int lo=0;
        int hi=nums.size()-1;
       int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(mid,nums)){
                ans=nums[mid];
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }return ans;
    }
    bool check(int mid,vector<int> &nums){
            if(nums[mid]<=nums[nums.size()-1])return true;
            return false;
        }
};
