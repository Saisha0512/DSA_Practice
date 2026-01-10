// BFS APPROACH : 
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // Iterating over the boundary elements : 
        for (int i = 0; i < n; i ++){
            // First col : 
            if (grid[i][0] == 1){
                vis[i][0] = true;
                q.push({i, 0});
            }
            // Last col : 
            if (grid[i][m - 1] == 1){
                vis[i][m - 1] = true;
                q.push({i, m - 1});
            }
        }
        for (int i = 0; i < m; i ++){
            // First row : 
            if (grid[0][i] == 1){
                vis[0][i] = true;
                q.push({0, i});
            }
            // Last row : 
            if (grid[n - 1][i] == 1){
                vis[n - 1][i] = true;
                q.push({n - 1, i});
            }
        }

        // BFS Loop : 
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;
                if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0){
                    continue;
                }

                vis[i][j] = true;
                q.push({i, j});
            }
        }

        // Checking all through all the cells : 
        int cnt = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == 1 && !vis[i][j]){
                    cnt ++;
                }
            }
        }

        return cnt;
    }
};