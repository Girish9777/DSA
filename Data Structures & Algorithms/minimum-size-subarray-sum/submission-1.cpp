class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int head=-1;
        int tail=0;
        int sum=0;
        int ans=INT_MAX;
        int n=nums.size();
        while(tail<n){
            while(head+1<n && sum<target  ){
                head++;
                sum+=nums[head];

            }
            if(sum>=target){
                ans=min(ans,head-tail+1);
            }
            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                sum-=nums[tail];
                tail++;
            }
        }
        if(ans!=INT_MAX){
            return ans;
        }return 0;
    }
};