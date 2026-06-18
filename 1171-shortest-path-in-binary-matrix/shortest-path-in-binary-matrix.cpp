class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // base case
        if (grid[0][0] != 0){
            return -1;
        }

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;

        // bfs loop
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            // if the destination is reached
            if (x == n - 1 && y == n - 1){
                return dist[x][y];
            }

            // iterating over the neighbors of the current node
            for (auto &[dx, dy] : dirs){
                int i = x + dx, j = y + dy;

                // boundary limits
                if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 0 || dist[i][j] != -1){
                    continue;
                }

                dist[i][j] = dist[x][y] + 1;
                q.push({i, j});
            }
        }

        return -1;
    }
};