class Solution {
public:

    int manDist(vector<vector<int>>& points, int p1, int p2) {

        return abs(points[p1][0] - points[p2][0]) +
               abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // {weight, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> vis(n, 0);

        int ans = 0;

        // start from point index 0
        pq.push({0, 0});

        while(!pq.empty()) {

            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(vis[node]) {
                continue;
            }

            vis[node] = 1;

            ans += wt;

            // current point ko har other unvisited point se connect try karo
            for(int next = 0; next < n; next++) {

                if(!vis[next]) {

                    int distance = manDist(points, node, next);

                    pq.push({distance, next});
                }
            }
        }

        return ans;
    }
};