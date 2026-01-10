class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void bfs(vector<vector<int>> &heights, queue<pair<int, int>> &q, vector<vector<bool>> &vis){
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;

                if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || vis[i][j] || heights[x][y] > heights[i][j]){
                    continue;
                }

                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false)), atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> q;
        // Pushing all the border elements in the queue for pacific first : 
        for (int i = 0; i < n; i ++){
            q.push({i, 0});
            pacific[i][0] = true;
        }
        for (int j = 0; j < m; j ++){
            q.push({0, j});
            pacific[0][j] = true;
        }
        bfs(heights, q, pacific);
        while (!q.empty())  q.pop();

        // Pushing all the border elements in the queue for atlantic ocean now : 
        for (int i = 0; i < n; i ++){
            q.push({i, m - 1});
            atlantic[i][m - 1] = true;
        }
        for (int j = 0; j < m; j ++){
            q.push({n - 1, j});
            atlantic[n - 1][j] = true;
        }
        bfs(heights, q, atlantic);

        // Checking for all the cells : 
        vector<vector<int>> res;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};