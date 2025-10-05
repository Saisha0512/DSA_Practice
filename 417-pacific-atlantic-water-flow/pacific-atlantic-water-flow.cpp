class Solution {
private : 
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int x, int y, vector<vector<int>> &height, vector<vector<bool>> &vis){
        int n = height.size(), m = height[0].size();
        vis[x][y] = true;

        for (auto [dx, dy] : dirs){
            int i = x + dx, j = y + dy;
            if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || height[i][j] < height[x][y]){
                continue;
            }

            dfs(i, j, height, vis);
        }
    }

public :
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));    

        // Traversing all the boundaries :  
        // Traversing the columns : 
        for (int i = 0; i < n; i ++){
            // First Column - Pacific Ocean : 
            if (!pacific[i][0]){
                dfs(i, 0, heights, pacific);
            }

            // Last Column - Atlantic Ocean : 
            if (!atlantic[i][m - 1]){
                dfs(i, m - 1, heights, atlantic);
            }
        }

        // Traversing the rows : 
        for (int i = 0; i < m; i ++){
            // First Row - Pacific Ocean : 
            if (!pacific[0][i]){
                dfs(0, i, heights, pacific);
            }

            // Last Row - Atlantic Ocean : 
            if (!atlantic[n - 1][i]){
                dfs(n - 1, i, heights, atlantic);
            }
        }

        // Adding into the result vector : 
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