class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    bool found;
    void dfs(int i){
        vis[i]=2;
        for(auto v:g[i]){
            if(vis[v]==1){
                dfs(v);
            }
            if(vis[v]==2)
{
    found=true;break;
}

        }
        vis[i]=3;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        vis.assign(numCourses,1);
        found=false;
        for(auto it:prerequisites){
            g[it[0]].push_back(it[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==1){
                dfs(i);
            }
        }
        if(found){
            return false;
        }
        return true;
        

    }
};
