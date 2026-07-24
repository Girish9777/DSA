class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int ans=0;
        int maxp=0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                maxp=prices[r]-prices[l];
                ans=max(ans,maxp);
            }
            else{
                l=r;
            }
            r++;
        }
        return ans;
    }
};
