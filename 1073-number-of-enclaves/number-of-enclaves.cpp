// DFS APPROACH : 
class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &vis){
        // Base Case : 
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 || vis[x][y]){
            return;
        }

        // Visiting the current cell : 
        vis[x][y] = true;

        // Recursive Case : 
        for (auto [dx, dy] : dirs){
            dfs(grid, x + dx, y + dy, vis);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        // Iterating over the boundary rows : 
        for (int i = 0; i < m; i ++){
            dfs(grid, 0, i, vis);
            dfs(grid, n - 1, i, vis);
        }
        // Iterating over the boundary columns : 
        for (int i = 0; i < n; i ++){
            dfs(grid, i, 0, vis);
            dfs(grid, i, m - 1, vis);
        }

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