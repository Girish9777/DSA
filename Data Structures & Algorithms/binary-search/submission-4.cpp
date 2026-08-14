class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=-1;
        int low=0;
        int hi=nums.size()-1;
        while(low<=hi){
            int mid=low+(hi-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(check(nums,target,mid)){
               hi=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool check(vector<int>& nums,int target,int mid){
        if(nums[mid]>target){
            return true;
        }return false;
    }
};
