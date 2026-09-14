class DisjointSet {
    vector<int> par, rank;

   public:
    DisjointSet(int n) {
        par.assign(n, 0);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        rank.assign(n, 1);
    }
    int findpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = findpar(par[x]);
    }
    void merge(int x, int y) {
        int px = findpar(x);
        int py = findpar(y);
        if (px != py) {
            if (rank[px] <= rank[py]) {
                rank[py] += rank[px];
                par[px] = py;
            } else {
                rank[px] += rank[py];
                par[py] = px;
            }
        }
    }
};
class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (ds.findpar(u) == ds.findpar(v)) {
                ans.push_back(u);
                ans.push_back(v);
            } else {
                ds.merge(u,v);
            }
        }
        return ans;
    }
};
