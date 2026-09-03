class Solution {
    #define F first
    #define S second
    using state=pair<int,int>;
public:
        vector<int> vis,dis;
        vector<vector<pair<int,int>>>g;
        void bfs(int node,int distance){
            dis[node]=distance;
            priority_queue<state,vector<state>,greater<state>> pq;
            pq.push({dis[node],node});
            while(!pq.empty())
            {
                state curr=pq.top(); // dist node
                pq.pop();
                if(vis[curr.S])continue;
                vis[curr.S]=1;
                for(auto v:g[curr.S]){
                    state front=v;
                    if(dis[curr.S]+v.S<dis[v.F]){
                    dis[v.F]=dis[curr.S]+v.S;
                    pq.push({dis[v.F],v.F});
                    }
                }
            }
        }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        g.resize(n+1);
        vis.assign(n+1,0);
          dis.assign(n+1,1e9);
          for(auto v: times){
            g[v[0]].push_back({v[1],v[2]});
          }dis[0]=0;
          int ans=0;
          bfs(k,0);
          for(int i=0;i<=n;i++){
            if(dis[i]==1e9)
            {
                return -1;
            } ans=max(ans,dis[i]);
          }
          return ans;

    }
};
