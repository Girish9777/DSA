class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int ans=0;
        int len=0;
        int minn=0;
        while(l<r){
            minn=min(heights[l],heights[r]);
            
            len=r-l;
            ans=max(ans,len*minn);
            if(heights[l]<heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;     
    }
};
