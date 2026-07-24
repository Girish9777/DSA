class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=0;
        int hi=0;
        for(int i=0;i<weights.size();i++){
            hi+=weights[i];
            if(lo<weights[i]){
                lo=weights[i];
            }
        }int mid;int ans=-1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(check(mid,weights,days)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }return ans;
    }
    bool check(int mid,vector<int>& weights,int days){
        int needed=1;int total=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(total+weights[i]<=mid){
                total+=weights[i];
            }else{
                needed++;
                total=weights[i];
            }
        }
        if(needed<=days) return true;
        return false;
    }
};