class Solution {
public:
    vector<vector<int>> g;
    vector<int> topo;
    vector<int> vis;bool found;
    void dfs(int i){
        vis[i]=2;
        for(auto v:g[i] ){
            if(vis[v]==1){
                dfs(v);
            }
            if(vis[v]==2){
                found=true;
            }


        }
        topo.push_back(i);
        vis[i]=3;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      int n=numCourses;
        vis.assign(n,1);
        g.resize(n);
        found=false;
        for(auto it:prerequisites){
            g[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==1){
                dfs(i);
            }
        }
        reverse(topo.begin(),topo.end());
        if(found){vector<int> ans;
            return ans;
        }  else{
            return topo;
        }
    }
};
