class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs_traversal(vector<vector<char>> &grid, vector<vector<bool>> &vis, int x, int y){
        int n = grid.size(), m = grid[0].size();
        vis[x][y] = true;

        for (auto &[dx, dy] : dir){
            int i = x + dx, j = y + dy;

            if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] != '1'){
                continue;
            }

            dfs_traversal(grid, vis, i, j);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    cnt ++;
                    dfs_traversal(grid, vis, i, j);
                }
            }
        }

        return cnt;
    }
};