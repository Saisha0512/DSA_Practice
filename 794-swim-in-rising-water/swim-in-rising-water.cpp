class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int t = 0;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()){
            auto [ht, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;
            vis[x][y] = true;
            t = max(t, ht);

            if (x == n - 1 && y == n - 1){
                return t;
            }

            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;
                if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j]){
                    continue;
                }

                vis[i][j] = true;
                pq.push({grid[i][j], {i, j}});
            }
        }

        return t;
    }
};