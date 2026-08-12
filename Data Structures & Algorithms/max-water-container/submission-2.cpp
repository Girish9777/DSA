class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int s=0;
        int e=heights.size()-1;
    while(s<e){
        int dis=e-s;
        int water=min(heights[s],heights[e])*dis;
        ans=max(ans,water);
        if(heights[s]<heights[e]){
            s++;
        }else{
            e--;
        }
    }
    return ans;
    }
};
