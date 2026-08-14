class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1;int ans=-1;
        int end=piles[piles.size()-1];
        while(low<=end){
            int mid=low+(end-low)/2;
            if(check(piles,h,mid)){
                ans=mid;
                end=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool check(vector<int>& piles,int h,int mid){
        int total=0;
        for(int i=0;i<piles.size();i++){
            int hour=(piles[i]+mid-1)/mid;
            total+=hour;
        }
        if(total<=h){
            return true;
        }
        else{
            return false;
        }
    }
};
