class Solution {
public:
    #define F first 
    #define S second
    using state=pair<int,int>;
    vector<vector<state>> g;
    vector<int> vis;
    vector<int> dis;
    void bfs(int distanece,int node){
        dis[node]=0;
        priority_queue<state,vector<state> ,greater<state>>pq;
        pq.push({0,node});
        while(!pq.empty()){
            state curr=pq.top();
            pq.pop();
            if(vis[curr.S])continue;
            vis[curr.S]=1;
            for(auto v:g[curr.S]){
                if(dis[v.F]>dis[curr.S]+v.S){
                    dis[v.F]=dis[curr.S]+v.S;
                    pq.push({dis[v.F],v.F});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        g.resize(n+1);
        vis.resize(n+1);
        dis.assign(n+1,1e9);
        for(auto it:times){
            g[it[0]].push_back({it[1],it[2]});

        }
        int ans=0;
        bfs(0,k);
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9){
                return -1;
            }
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};
