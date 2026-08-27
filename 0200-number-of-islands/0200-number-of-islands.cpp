class Solution {
public:
    void dfs(vector<vector<bool>>& vis, vector<vector<char>>& grid,
             int i, int j, int n, int m)
    {
        if(i < 0 || j < 0 || i >= n || j >= m ||
           grid[i][j] != '1' || vis[i][j])
        {
            return;
        }

        vis[i][j] = true;

        dfs(vis, grid, i - 1, j, n, m);
        dfs(vis, grid, i, j + 1, n, m);
        dfs(vis, grid, i, j - 1, n, m);
        dfs(vis, grid, i + 1, j, n, m);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(vis, grid, i, j, n, m);
                    island++;
                }
            }
        }

        return island;
    }
};