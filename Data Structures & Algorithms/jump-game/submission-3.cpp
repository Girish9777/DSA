#include <cstring>
class Solution {
public:
    int dp[1003];
    bool rec(int level,vector<int>& nums){
        if(level>=nums.size()-1){
            return true;
        }
        if(dp[level]!=-1){
            return dp[level];
        }
        bool ans=false;
        for(int i=1;i<=nums[level];i++){
            if( rec(level+i,nums)){
                ans= true;
            }
        }
      return dp[level]=ans;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(0,nums);
    }
};
