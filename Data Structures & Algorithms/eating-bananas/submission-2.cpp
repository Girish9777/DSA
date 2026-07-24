class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minn=INT_MAX;
        int maxx=INT_MIN;
int n=piles.size();
        sort(piles.begin(),piles.end());
        minn=piles[0];
        maxx=piles[n-1];
        int lo=1;int ans=0;
        int hi=maxx;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
          if(check(piles,h,mid)){
                ans=mid;
                hi=mid-1
                ;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
    bool check(vector<int> &piles,int h,int mid){
        int total=0;
        
        for(int i=0;i<piles.size();i++){
            total+=((piles[i]+mid-1)/mid);
        } 
        if(total<=h){
            return true;
        }else{
            return false;
        }
    }
};
