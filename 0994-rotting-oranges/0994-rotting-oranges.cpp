class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        // visited matrix initialized to false
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // queue to store {{i, j}, time}
        queue<pair<pair<int, int>, int>> q;

        // Step 1: Push all sources into Q (Multi-source BFS)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        // Step 2: BFS Traversal
        while (q.size() > 0) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            // Top neighbor (i-1, j)
            if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1) {
                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }

            // Right neighbor (i, j+1)
            if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1) {
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }

            // Bottom neighbor (i+1, j)
            if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1) {
                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }

            // Left neighbor (i, j-1)
            if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {
                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }
        }

        // Step 3: Check for any remaining unreachable fresh orange
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};