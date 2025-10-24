class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (mat[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;
                if (i >= 0 && j >= 0 && i < n && j < m && res[i][j] == -1){
                    res[i][j] = res[x][y] + 1;
                    q.push({i, j});
                }
            }
        }

        return res;
    }
};