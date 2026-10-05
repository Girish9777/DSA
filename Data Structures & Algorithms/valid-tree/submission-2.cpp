class Solution {
public:
    vector<int> par,vis;
    bool found;vector<vector<int>> g;

    void dfs(int node,int parent)
    {   par[node]=parent;
        vis[node]=2;
        for(auto v:g[node]){
            if(v==par[node]){
                continue;
            }
            if(vis[v]==1){
                dfs(v,node);
            }
            if(vis[v]==2){
                found=true;
                break;
            }
        }
        vis[node]=3;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
             g[it[1]].push_back(it[0]);
        }
        found=false;
        vis.assign(n,1);
        par.assign(n,-1);
        int m= 0;
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                m++;
                dfs(i,0);
                
            }
        }
        if(m!=1){
            return false;
        }
        if(found){
            return false;
        }
        return true;

    }
};
