
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int,int>> q;

        q.push({0,0});
        visited[0][0] = 1;

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        int dist = 1;

        while(!q.empty()) {
            int size = q.size();

            for(int j = 0; j < size; j++) {
                auto [x,y] = q.front();
                q.pop();

                if(x == n-1 && y == n-1)
                    return dist;

                for(int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if(grid[nx][ny] == 0 && !visited[nx][ny]) {
                            visited[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
            }

            dist++;
        }

        return -1;
    }
};
