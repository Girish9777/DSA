class DisjointSet {
   public:
    vector<int> par, size;
    DisjointSet(int n) {
        par.assign(n,0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int findparent(int x) {
        if (x == par[x]) {
            return x;
        }
        return par[x] = findparent(par[x]);
    }
    void merge(int x, int y) {
        int px = findparent(x);
        int py = findparent(y);
        if (px == py) {
            return;
        }
        if (size[px] <= size[py]) {
            par[px] = py;
            size[py] += size[px];
        }
        if (size[py] < size[px]) {
            par[py] = par[px];
            size[px] += size[py];
        }
    }
};
 class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        DisjointSet ds(n);
        vector<int> ans;
        for (int i = 0; i<n-1; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            if (ds.findparent(x) == ds.findparent(y)) {
                ans.push_back(x);
                ans.push_back(y);
            } else {
                ds.merge(x, y);
            }
        }
        return ans;
    }
};
