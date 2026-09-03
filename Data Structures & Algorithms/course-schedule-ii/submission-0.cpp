class Solution {
public:
    vector<int> vis;vector<int> ans;
    vector<vector<int>> g;
    int n;
    bool found=false;
    void dfs(int node){
        vis[node]=1;
        for(auto v:g[node]){
            if(vis[v]==0){
                dfs(v);
            }
            if(vis[v]==1){
                found=true;
                break;
            }

        }
        vis[node]=2;
        ans.push_back(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        
        g.resize(n);
        vis.assign(n,0);
        for(auto it:prerequisites){
            g[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i);
            }
        }
        reverse(ans.begin(),ans.end());
        if(found){
            vector<int> temp;
            return temp;
        }else{
            return ans;
        }
    }
};
