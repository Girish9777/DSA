class Solution {
    #define F first
    #define S second
    using state = pair<int,int>;

public:
    vector<vector<int>> dis, vis;

    bool check(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // We can only move to a fresh fruit.
        if(i >= 0 && i < n &&
           j >= 0 && j < m &&
           grid[i][j] == 1) {
            return true;
        }

        return false;
    }

    vector<state> neig(int i, int j, vector<vector<int>>& grid) {
        vector<state> ans;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(check(x, y, grid)) {
                ans.push_back({x, y});
            }
        }

        return ans;
    }

    void bfs(queue<state> q, vector<vector<int>>& grid) {

        while(!q.empty()) {

            state curr = q.front();

            // ERROR:
            // You forgot to remove the current element from queue.
            q.pop();

            int x = curr.F;
            int y = curr.S;

            for(auto v : neig(x, y, grid)) {

                if(dis[v.F][v.S] > dis[x][y] + 1) {

                    dis[v.F][v.S] = dis[x][y] + 1;

                    vis[v.F][v.S] = 1;

                    q.push({v.F, v.S});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<state> q;

        dis.assign(n, vector<int>(m, 1e9));
        vis.assign(n, vector<int>(m, 0));

        // Multi-source BFS initialization
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});

                    dis[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        bfs(q, grid);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // ERROR IN YOUR CODE:
                // if(grid[i][j] != 1 && dis[i][j] == 1e9) {
                //     continue;
                // }
                //
                // else if(grid[i][j] != 1 &&
                //         dis[i][j] == 1e9 &&
                //         vis[i][j] == 0) {
                //     return -1;
                // }
                //
                // Problem:
                // The second condition can never execute because
                // the first condition already catches it.

                // Correct logic:
                // If a FRESH fruit was never reached,
                // it can never become rotten.
                if(grid[i][j] == 1 && dis[i][j] == 1e9) {
                    return -1;
                }

                // Only fruit cells matter for answer.
                if(grid[i][j] == 1) {
                    ans = max(ans, dis[i][j]);
                }
            }
        }

        return ans;
    }
};