class Solution {
    #define F first
    #define S second
    using state = pair<int,int>;

public:
    vector<vector<int>> vis;
    vector<vector<state>> components;

    bool check(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 0) {
            return true;
        }
        return false;
    }

    vector<state> neigh(int i, int j, vector<vector<int>>& grid) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        vector<state> ans;

        for(int k = 0; k < 4; k++) {
            int x = dx[k] + i;
            int y = dy[k] + j;

            if(check(x, y, grid)) {
                ans.push_back({x, y});
            }
        }

        return ans;
    }

    void dfs(int i, int j, int comp_no, vector<vector<int>>& grid) {
        vis[i][j] = 1;

        components[comp_no].push_back({i, j});

        for(auto v : neigh(i, j, grid)) {
            int xx = v.F;
            int yy = v.S;

            if(!vis[xx][yy]) {
                dfs(xx, yy, comp_no, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int comp_no = 0;

        vis.assign(n, vector<int>(m, 0));

        // ERROR:
        // components.assign(n, vector<int>(m, 0));
        //
        // components is vector<vector<state>>
        // We only need n*m empty component vectors.
        components.assign(n * m, vector<state>());

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(!vis[i][j] && grid[i][j] != 0) {

                    // ERROR:
                    // comp_np++;
                    // Typo: variable is comp_no

                    // ERROR IN LOGIC:
                    // comp_no++ before dfs would make first component index = 1.
                    // Better: first DFS using current comp_no,
                    // then increment for next component.

                    dfs(i, j, comp_no, grid);
                    comp_no++;
                }
            }
        }

        int ans = 0;

        for(auto v : components) {
            int size = v.size();

            // ERROR:
            // ans = max(size, ans);
            // size is int here, so this is actually valid.
            // No correction required.
            
            ans = max(size, ans);
        }

        return ans;
    }
};