class Solution {
    #define F first
    #define S second
    using state=pair<int,pair<int,int>>;
public:
    int maxflights;
    vector<vector<pair<int,int>>> g;
    vector<vector<int>> dis,vis;
    void bfs(int distance,int node,int k)
    {
     priority_queue<state,vector<state>,greater<state>> pq;
     pq.push({distance,{node,k}});
     while(!pq.empty())
     {
        state curr=pq.top();
       
        int cost=pq.top().F;
        int node=pq.top().S.F;
        int flight=pq.top().S.S; pq.pop();
        if(vis[node][flight]){
            continue;
        }
        vis[node][flight]=1;
        for(auto v:g[node]){
            int neigh=v.F;
            int c=v.S;
            if(flight+1<=maxflights){
                if(dis[neigh][flight+1]>dis[node][flight]+c){
                  dis[neigh][flight+1]=dis[node][flight]+c;
                  pq.push({dis[neigh][flight+1],{neigh,flight+1}})  ;
                }
            }
        }
     }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        g.resize(n);
        int m=flights.size();
        for(auto it:flights){
            g[it[0]].push_back({it[1],it[2]});
        }
        maxflights=k+1;
        vis.assign(n,vector<int>(maxflights+1,0));
        dis.assign(n,vector<int>(maxflights+1,1e9));
        dis[src][0]=0;
        bfs(0,src,0);
        int ans=1e9;
        for(int i=0;i<=maxflights;i++){
            ans=min(ans,dis[dst][i]);
        }
        if(ans==1e9){
            return -1;
        }
        return ans;


    }
};
