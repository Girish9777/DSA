class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> s;
        int n=heights.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }else{
                left[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
         for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty() &&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=n;
            }else{
                right[i]=s.top();
            }
            s.push(i);
        }
        int curr=0;
        for(int i=0;i<heights.size();i++){
                ans=heights[i]*(right[i]-left[i]-1);
                curr=max(ans,curr);
        }
        return curr;
    }
};
