class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size(); vector<int> pgreat(n,0);
        vector<int> ngreat(n,0);
         pgreat[0]=height[0];
        for(int i=1;i<height.size();i++){
                pgreat[i]=max(pgreat[i-1],height[i]);
        }
         ngreat[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            ngreat[i]=max(ngreat[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(ngreat[i],pgreat[i])-height[i];
        }
        return ans;
        
        
    }
};
