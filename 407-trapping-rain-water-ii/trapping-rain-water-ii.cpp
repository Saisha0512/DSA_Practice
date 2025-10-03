class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size(), m = height[0].size();
        if (n <= 2 || m <= 2){
            return 0;
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Min - heap : 
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Pushing all the boundary cells : 
        for (int i = 0; i < n; i ++){
            pq.push({height[i][0], i, 0});
            pq.push({height[i][m - 1], i, m - 1});
            vis[i][0] = vis[i][m - 1] = true;
        }
        for (int j = 0; j < m; j ++){
            pq.push({height[0][j], 0, j});
            pq.push({height[n - 1][j], n - 1, j});
            vis[0][j] = vis[n - 1][j] = true;
        }

        int total = 0, maxht = 0;
        while (!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int ht = curr[0], x = curr[1], y = curr[2];
            maxht = max(maxht, ht);

            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;
                if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j]){
                    continue;
                }

                vis[i][j] = true;
                // If the neighbour is lower, water trapped = maxht - neighbour ht
                if (height[i][j] < maxht){
                    total += maxht - height[i][j];
                }
                pq.push({height[i][j], i, j});
            }
        }
        return total;
    }
};