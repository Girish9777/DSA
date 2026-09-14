class Solution {
    #define F first
    # define S second
    using state=pair<int,pair<int,int>>;
public:
    vector<vector<pair<int,int>>> g;
   vector<vector<int>> vis,dis;
    int c;
    void bfs(pair<int,pair<int,int>> node){
        priority_queue<state,vector<state>,greater<state>> pq;
        pq.push({node.F,{node.S.F,node.S.S}}); // cost node flight
    
        while(!pq.empty()){
            state curr=pq.top();
            pq.pop();
            int  cost=curr.F;
            int x=curr.S.F;
            int flight=curr.S.S;
            if(vis[x][flight])continue;
            vis[x][flight]=1;
            for(auto v:g[x]){
            if(flight+1<=c &&  dis[v.F][flight+1]>dis[x][flight]+v.S) {
             dis[v.F][flight+1]=dis[x][flight]+v.S;
             pq.push({dis[v.F][flight+1],{v.F,flight+1}});
            
            }
        }

        }
    
    }


    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         // ✅ ERROR FIX
        vis.assign(n, vector<int>(c+99, 0)); 
        dis.assign(n, vector<int>(c+99, 1e9)); 
        g.resize(n);

        for(auto it:flights){
            g[it[0]].push_back({it[1],it[2]}); // node price;



        }
        c=k+1;
        dis[src][0]=0;
        bfs({0,{src,0}}); // cost node k 
         int ans = 1e9;

        // destination can be reached using
        // 1, 2, ..., c flights
        for(int flight = 0; flight <= c; flight++) {
            ans = min(ans, dis[dst][flight]);
        }

        if(ans == 1e9)
            return -1;

        return ans;
         


    }
};
