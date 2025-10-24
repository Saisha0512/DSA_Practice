class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // Min - Heap
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        pq.push({0, {0, 0}});
        int maxeffort = 0;

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int effort = curr.first, x = curr.second.first, y = curr.second.second;
            
            maxeffort = max(maxeffort, effort);
            if (x == n - 1 && y == m - 1){
                return maxeffort;
            }

            vis[x][y] = true;
            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;
                if (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j]){
                    int neweff = abs(heights[i][j] - heights[x][y]);
                    pq.push({neweff, {i, j}});
                }
            }
        }
        
        return maxeffort;
    }
};