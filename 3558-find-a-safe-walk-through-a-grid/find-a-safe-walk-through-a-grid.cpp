class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        deque<pair<int, int>> dq;
        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        while (!dq.empty()){
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto &[dx, dy] : dir){
                int i = x + dx, j = y + dy;

                if (i < 0 || i >= n || j < 0 || j >= m){
                    continue;
                }

                // finding the minimum cost to reach (n - 1, m - 1)
                int new_cost = dist[x][y] + grid[i][j];
                if (new_cost < dist[i][j]){
                    dist[i][j] = new_cost;
                    
                    if (grid[i][j] == 0){
                        dq.push_front({i, j});
                    }
                    else {
                        dq.push_back({i, j});
                    }
                }
            }
        }

        return (health - dist[n - 1][m - 1] >= 1);
    }
};