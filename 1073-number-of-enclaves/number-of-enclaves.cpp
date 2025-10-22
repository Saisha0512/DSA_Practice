class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        int n = grid.size(), m = grid[0].size();
        vis[x][y] = true;

        for (auto [dx, dy] : dirs){
            int i = x + dx, j = y + dy;
            if (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 1 && !vis[i][j]){
                dfs(i, j, grid, vis);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        // Pushing all the boundary cells in the queue : 
        for (int i = 0; i < n; i ++){
            // First Column : 
            if (grid[i][0] == 1){
                q.push({i, 0});
                vis[i][0] = true;
            }

            // Last Column : 
            if (grid[i][m - 1] == 1){
                q.push({i, m - 1});
                vis[i][m - 1] = true;
            }
        }

        for (int i = 0; i < m; i ++){
            // First Row : 
            if (grid[0][i] == 1){
                q.push({0, i});
                vis[0][i] = true;
            }

            // Last Row : 
            if (grid[n - 1][i] == 1){
                q.push({n - 1, i});
                vis[n - 1][i] = true;
            }
        }

        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            dfs(x, y, grid, vis);
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