class Solution {
    public int maxProfit(int[] prices) {
        int s=0;
        int e=1;int ans=0;
        for(int i=e;i<prices.length;i++){
            if(prices[s]>prices[e]){
                s=e;
            }
            else{
                int p=prices[e]-prices[s];
                if(p>ans){
                    ans=p;
                }
            }
            e++;
        }
        return ans;
    }
}
