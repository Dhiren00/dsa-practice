class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid, int r, int c, int expected, int n) {
        // Bounds check first
        if (r < 0 || r >= n || c < 0 || c >= n) return false;

        // Value check
        if (grid[r][c] != expected) return false;

        // Base case: last cell
        if (grid[r][c] == n*n - 1) return true;

        // Try all knight moves
        return checkValidGrid(grid, r-2, c+1, expected+1, n) ||
               checkValidGrid(grid, r-1, c+2, expected+1, n) ||
               checkValidGrid(grid, r+1, c+2, expected+1, n) ||
               checkValidGrid(grid, r+2, c+1, expected+1, n) ||
               checkValidGrid(grid, r+2, c-1, expected+1, n) ||
               checkValidGrid(grid, r+1, c-2, expected+1, n) ||
               checkValidGrid(grid, r-1, c-2, expected+1, n) ||
               checkValidGrid(grid, r-2, c-1, expected+1, n);
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        // Start from (0,0) with expected=0
        return checkValidGrid(grid, 0, 0, 0, n);
    }
};