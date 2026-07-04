class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0){
            return -1;
        }
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {dist, x, y}
        pq.push({1, 0, 0});
        dist[0][0] = 1;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}};

        while (!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int curr_dist = curr[0], x = curr[1], y = curr[2];

            if (curr_dist > dist[x][y]){
                continue;
            }

            for (auto &[dx, dy] : dir){
                int i = x + dx, j = y + dy;

                if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 1){
                    continue;
                }

                int new_dist = curr_dist + 1;
                if (new_dist < dist[i][j]){
                    dist[i][j] = new_dist;
                    pq.push({dist[i][j], i, j});
                }
            }
        }

        return (dist[n - 1][n - 1] == INT_MAX)? -1 : dist[n - 1][n - 1];
    }
};