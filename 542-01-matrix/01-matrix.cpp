class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        // pushing all the 0s into the queue
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (mat[i][j] == 0){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (auto &[dx, dy] : dir){
                int i = x + dx, j = y + dy;

                if (i < 0 || j < 0 || i >= n || j >= m || dist[i][j] <= dist[x][y] + 1){
                    continue;
                }

                dist[i][j] = dist[x][y] + 1;
                q.push({i, j});
            }
        }

        return dist;
    }
};