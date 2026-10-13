class Solution {
public:
    int findMin(vector<int> &nums) {
        int s=0;
        int last=nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        int e=nums.size()-1; int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
                if(nums[mid]<=nums[last]){
                    ans=nums[mid];
                    e=mid-1;
                }else{
                    s=mid+1;
                }
        }
        return ans;
    }
};
