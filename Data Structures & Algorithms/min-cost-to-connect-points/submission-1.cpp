class Solution {
    using state=pair<int,int> ;
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> vis;int ans=0;
    void mst(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            state curr=pq.top();
            pq.pop();
            int weight=curr.first;
            int node=curr.second;
            if(vis[node]){
                continue;
            }
            vis[node]=1;
            ans+=weight;
            for(auto v:adj[node]){
                int neigh=v.first;
                int cost=v.second;
                if(!vis[neigh]){
                    pq.push({cost,neigh});
                }
            }
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        adj.resize(n);
        for(int i=0;i<n-1;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                    int x2=points[j][0];
                    int y2=points[j][1];
                  int   dist=abs(x2-x1)+abs(y2-y1);
                    adj[i].push_back({j,dist});
                        adj[j].push_back({i,dist});
            }
        }   
        vis.assign(n,0);
        mst();
        return ans;
            
        
    }
};
