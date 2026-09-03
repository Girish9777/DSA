class Solution {
public:
    vector<int> par;
    vector<int> vis;
    vector<vector<int>> g; bool found=false;
    void dfs(int node,int parent){
        vis[node]=1;
        par[node]=parent;
        for(auto v:g[node]){
            if(v==par[node]){
                continue;
            }
            if(vis[v]==0){
                dfs(v,node);
            }
            if(vis[v]==1){
                found=true;
                break;
            }
        }
        vis[node]=2;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vis.assign(n,0);
        par.assign(n,-1);
      g.resize(n);
      for(auto v:edges){
        g[v[0]].push_back(v[1]);
         g[v[1]].push_back(v[0]);
      }
        int number=0;
        for(int i=0;i<n;i++)
        {   
            if(!vis[i]){
                number++;
                dfs(i,0);
            }
        }
        if(number!=1){
            return false;
        }
        if(found){
            return false;
        }return true;
    }
};
