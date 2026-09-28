class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newcolor,
             vector<vector<bool>>& visited, int n, int n1, int original)
    {
        if(i < 0 || j < 0 || i >= n || j >= n1 ||
           visited[i][j] || image[i][j] != original)
        {
            return;
        }

        visited[i][j] = true;
        image[i][j] = newcolor;

        dfs(image, i - 1, j, newcolor, visited, n, n1, original);
        dfs(image, i + 1, j, newcolor, visited, n, n1, original);
        dfs(image, i, j - 1, newcolor, visited, n, n1, original);
        dfs(image, i, j + 1, newcolor, visited, n, n1, original);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int n = image.size();
        int n1 = image[0].size();

        int original = image[sr][sc];

        vector<vector<bool>> visited(n, vector<bool>(n1, false));

        dfs(image, sr, sc, color, visited, n, n1, original);

        return image;
    }
};