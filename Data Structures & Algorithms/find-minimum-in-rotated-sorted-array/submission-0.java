class Solution {
    public int findMin(int[] nums) {
        int lo=0;
        int hi=nums.length;                
        int ans=0;
       
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(nums[mid]<=nums[nums.length-1]){
                ans=nums[mid];

                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
}
