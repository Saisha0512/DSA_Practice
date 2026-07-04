class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        // pushing the boundary 1s 
        // first col & last col
        for (int i = 0; i < n; i ++){
            if (grid[i][0] == 1){
                q.push({i, 0});
                vis[i][0] = true;
            }
            if (grid[i][m - 1] == 1){
                q.push({i, m - 1});
                vis[i][m - 1] = true;
            }
        }
        // first row & last row
        for (int i = 0; i < m; i ++){
            if (grid[0][i] == 1){
                q.push({0, i});
                vis[0][i] = true;
            }
            if (grid[n - 1][i] == 1){
                q.push({n - 1, i});
                vis[n - 1][i] = true;
            }
        }

        // visiting all the lands through which we can walk off the boundary
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (auto &[dx, dy] : dir){
                int i = x + dx, j = y + dy;

                if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != 1){
                    continue;
                }

                vis[i][j] = true;
                q.push({i, j});
            }
        }

        // counting the number of unvisited lands
        int cnt = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (!vis[i][j] && grid[i][j] == 1){
                    cnt ++;
                }
            }
        }

        return cnt;
    }
};