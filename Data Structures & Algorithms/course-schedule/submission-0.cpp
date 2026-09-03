class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    bool found = false;

    void dfs(int node) {
        vis[node] = 2;

        for (auto v : g[node]) {
            if (vis[v] == 1) {
                dfs(v);
            }

            if (vis[v] == 2) {
                found = true;
                break;
            }
        }

        vis[node] = 3;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        g.resize(numCourses);
        int n = numCourses;

        for (auto it : prerequisites) {
            g[it[0]].push_back(it[1]);
        }

        vis.assign(n, 1);
        found = false;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) {
                dfs(i);
            }
        }

        if (found) {
            return false;
        }

        return true;
    }
};