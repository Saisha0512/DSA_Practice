class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool checkIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>> &vis, int x, int y){
        int n = grid1.size(), m = grid1[0].size();
        vis[x][y] = true;
        bool flag = (grid1[x][y] == 1);

        for (auto &[dx, dy] : dir){
            int i = x + dx, j = y + dy;

            if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid2[i][j] == 0){
                continue;
            }

            bool check = checkIslands(grid1, grid2, vis, i, j);

            if (!check){
                flag = false;
            }
        }

        return flag;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();

        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (!vis[i][j] && grid2[i][j] == 1){
                    bool check = checkIslands(grid1, grid2, vis, i, j);

                    if (check){
                        cnt ++;
                    }
                }
            }
        }

        return cnt;
    }
};