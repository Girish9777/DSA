class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair <double,vector<int>>> pq;
        for(int i=0;i<points.size();i++){
            int a=points[i][0];
            int b=points[i][1];
            double x=a*a+b*b;
            double ans=sqrt(x);
            pq.push({ans,points[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
