class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    
    void dfs(int node,int comp_no){
        vis[node]=1;
        for(auto v:g[node]){
            if(!vis[v]){
                dfs(v,comp_no);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        g.resize(n);
        vis.assign(n,0);
        for(auto v:edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int comp_no=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp_no++;
                dfs(i,comp_no);
            }
        }
        return comp_no;
    }
};
