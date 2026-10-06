class Solution {
    using state = pair<int, int>;

public:
    vector<vector<int>> vis1, vis2;

    vector<state> neig(
        int i,
        int j,
        vector<vector<int>>& vis,   // ERROR FIX: vector<int>& vis -> vector<vector<int>>& vis
        vector<vector<int>>& heights
    ) {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        int n = heights.size();
        int m = heights[0].size();

        vector<state> ans;

        for (int k = 0; k < 4; k++) {
            int x = dx[k] + i;
            int y = dy[k] + j;

            if (
                x >= 0 && y >= 0 &&
                x < n && y < m &&
                !vis[x][y] &&
                heights[x][y] >= heights[i][j]   // ERROR FIX: heights[x][j] -> heights[x][y]
            ) {
                ans.push_back({x, y});
            }
        }

        return ans;
    }

    void dfs(int i,int j,
        vector<vector<int>>& vis,   // ERROR FIX: vector<int>& vis -> vector<vector<int>>& vis
        vector<vector<int>>& heights
    ) {
        vis[i][j] = 1;

        for (auto v : neig(i, j, vis, heights)) {
            if (!vis[v.first][v.second]) {
                dfs(v.first, v.second, vis, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> ans;

        int n = heights.size();
        int m = heights[0].size();

        vis1.assign(n, vector<int>(m, 0));
        vis2.assign(n, vector<int>(m, 0));

        // Pacific Ocean -> top row
        // ERROR FIX:
        // for(int i = 0; i < n; i++)
        // Top row has m columns, so loop should run till m.
        for (int i = 0; i < m; i++) {

            // ERROR FIX: vis[0][i] -> vis1[0][i]
            if (!vis1[0][i]) {
                dfs(0, i, vis1, heights);  // ERROR FIX: heights parameter was missing
            }
        }

        // Pacific Ocean -> left column
        // ERROR FIX:
        // for(int i = 0; i < m; i++)
        // Left column has n rows.
        for (int i = 0; i < n; i++) {

            // ERROR FIX: vis[i][0] -> vis1[i][0]
            if (!vis1[i][0]) {
                dfs(i, 0, vis1, heights);
            }
        }

        // Atlantic Ocean -> bottom row
        // ERROR FIX:
        // for(int i = 0; i < n; i++)
        // Bottom row has m columns.
        for (int i = 0; i < m; i++) {

            // ERROR FIX: vis[n-1][i] -> vis2[n-1][i]
            if (!vis2[n - 1][i]) {
                dfs(n - 1, i, vis2, heights);
            }
        }

        // Atlantic Ocean -> right column
        for (int i = 0; i < n; i++) {

            // ERROR:
            // if(!vis[i][m-i])
            //
            // Rightmost column is always m-1.
            // m-i is not the right border and can even go out of bounds.

            if (!vis2[i][m - 1]) {
                dfs(i, m - 1, vis2, heights);
            }
        }

        // Cells reachable from both oceans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (vis1[i][j] && vis2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};