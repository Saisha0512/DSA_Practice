class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs_traversal(vector<vector<int>> &land, vector<vector<bool>> &vis, int x, int y, int &min_row, int &max_row, int &min_col, int &max_col, int &cells){
        int n = land.size(), m = land[0].size();
        vis[x][y] = true;
        cells ++;
        min_row = min(min_row, x);
        max_row = max(max_row, x);
        min_col = min(min_col, y);
        max_col = max(max_col, y);

        for (auto &[dx, dy] : dir){
            int i = x + dx, j = y + dy;

            if (i < 0 || j < 0 || i >= n || j >= m || land[i][j] == 0 || vis[i][j]){
                continue;
            }

            dfs_traversal(land, vis, i, j, min_row, max_row, min_col, max_col, cells);
        }
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();

        vector<vector<int>> res;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (!vis[i][j] && land[i][j] == 1){
                    int min_row = i, max_row = i, min_col = j, max_col = j;
                    int cells = 0;

                    dfs_traversal(land, vis, i, j, min_row, max_row, min_col, max_col, cells);

                    int height = max_row - min_row + 1, width = max_col - min_col + 1;
                    if (cells == height * width){
                        res.push_back({min_row, min_col, max_row, max_col});
                    }
                }
            }
        }

        return res;
    }
};