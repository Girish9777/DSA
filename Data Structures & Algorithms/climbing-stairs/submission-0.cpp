#include <cstring>
class Solution {
public:
    int dp[47];
    int rec(int level,int  n){
        if(level==n){
            return 1;
        }
        int ans=0;
        if(dp[level]!=-1){
            return dp[level];
        }
        for(int i=1;i<3;i++){
            if(level+i<=n){
                ans+=rec(level+i,n);
            }
        }
        return dp[level]=ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
       return rec(0,n); 
    }
};
