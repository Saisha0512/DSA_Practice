class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1){
            return -1;
        }

        int n = grid.size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push({0, 0});
        vis[0][0] = true;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        int steps = 1;
        while (!q.empty()){
            int size = q.size();

            while (size --){
                auto [x, y] = q.front();
                q.pop();

                if (x == n - 1 && y == n - 1){
                    return steps;
                }

                for (auto &[dx, dy] : dir){
                    int i = x + dx, j = y + dy;

                    if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || grid[i][j] == 1){
                        continue;
                    }

                    q.push({i, j});
                    vis[i][j] = true;
                }
            }

            steps ++;
        }

        return -1;
    }
};