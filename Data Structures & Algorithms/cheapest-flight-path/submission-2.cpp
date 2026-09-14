class Solution {
    #define F first
    #define S second

    using state = pair<int,pair<int,int>>;

public:

    vector<vector<pair<int,int>>> g;
    vector<vector<int>> vis, dis;
    int c;

    void bfs(state node) {

        priority_queue<
            state,
            vector<state>,
            greater<state>
        > pq;

        pq.push({node.F,{node.S.F,node.S.S}});

        while(!pq.empty()) {

            state curr = pq.top();
            pq.pop();

            int cost = curr.F;
            int x = curr.S.F;
            int flight = curr.S.S;

            if(vis[x][flight])
                continue;

            vis[x][flight] = 1;

            for(auto v : g[x]) {

                if(flight + 1 <= c &&
                   dis[v.F][flight+1] > dis[x][flight] + v.S)
                {
                    dis[v.F][flight+1] =
                        dis[x][flight] + v.S;

                    pq.push({
                        dis[v.F][flight+1],
                        {v.F,flight+1}
                    });
                }
            }
        }
    }


    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        g.resize(n);

        for(auto it : flights) {
            g[it[0]].push_back({it[1],it[2]});
        }

        // ✅ FIRST calculate maximum flights
        c = k + 1;

        // ✅ FIXED: second dimension is flights used
        // flight can be 0,1,2,...,c
        vis.assign(n, vector<int>(c+1, 0));
        dis.assign(n, vector<int>(c+1, 1e9));

        dis[src][0] = 0;

        bfs({0,{src,0}});

        int ans = 1e9;

        for(int flight = 0; flight <= c; flight++) {
            ans = min(ans, dis[dst][flight]);
        }

        if(ans == 1e9)
            return -1;

        return ans;
    }
};