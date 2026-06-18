class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<int>> effort(n, vector<int> (m, INT_MAX));
        queue<pair<int, int>> q; // {x, y}
        q.push({0, 0});
        effort[0][0] = 0;
        
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            int curr_eff = effort[x][y];

            // reached the destination
            if (x == n - 1 && y == m - 1){
                continue;
            }

            // checking the effort to reach the neighbors from the current cell
            for (auto &[dx, dy] : dirs){
                int i = x + dx, j = y + dy;

                // out of boundary
                if (i < 0 || j < 0 || i >= n || j >= m){
                    continue;
                }

                int new_eff = max(curr_eff, abs(heights[x][y] - heights[i][j]));
                if (new_eff < effort[i][j]){
                    effort[i][j] = new_eff;
                    q.push({i, j});
                }
            }
        }

        return effort[n - 1][m - 1];
    }
};