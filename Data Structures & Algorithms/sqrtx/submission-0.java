class Solution {
    public int mySqrt(int x) {
        int lo=0;
        int hi=x;int ans=0;
        while(lo<=hi){
            long mid=lo+(hi-lo)/2;
            long val=mid*mid;
            if(val<=x){
                ans=(int)mid;
                lo=(int)mid+1;
            }else{
                hi=(int)mid-1;
            }
        }
        return ans;
    }
}