class Solution {
public:
    bool check(int mid,vector<int> & piles,int h){
        int hour=0;
        for(int i=0;i<piles.size();i++){
            hour+=(piles[i]+mid-1)/mid;
        }
        if(hour<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=piles.size()-1;
        for(int i=0;i<piles.size();i++){
            e=max(e,piles[i]);
        }int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(check(mid,piles,h)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
