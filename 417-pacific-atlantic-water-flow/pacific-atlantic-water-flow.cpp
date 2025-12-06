class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int x, int y){
        int n = heights.size(), m = heights[0].size();
        // Marking the current node as visited : 
        vis[x][y] = true;

        for (auto [dx, dy] : dirs){
            int i = x + dx, j = y + dy;

            if (i < 0 || j < 0 || i >= n || j >= m || heights[i][j] < heights[x][y] || vis[i][j]){
                continue;
            }

            dfs(heights, vis, i, j);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Traversing the boundaries :
        // Traversing the columns : 
        for (int i = 0; i < n; i ++){
            // First column : 
            if (!pacific[i][0]){
                dfs(heights, pacific, i, 0);
            }

            // Last Column : 
            if (!atlantic[i][m - 1]){
                dfs(heights, atlantic, i, m - 1);
            }
        }
        // Traversing the rows : 
        for (int i = 0; i < m; i ++){
            // First Row : 
            if (!pacific[0][i]){
                dfs(heights, pacific, 0, i);
            }
            // Last Row : 
            if (!atlantic[n - 1][i]){
                dfs(heights, atlantic, n - 1, i);
            }
        }


        // Iterating to check all the cells who can send water to both pacific & atlantic ocean : 
        vector<vector<int>> res;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (atlantic[i][j] && pacific[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};