class Solution {
    int calculateSum(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j){
        // Base Case : 
        if (i == 0 && j == 0){
            return grid[i][j];
        }
        if (i < 0 || j < 0){
            return INT_MAX;
        }

        // Check DP :
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // Recursive Case : 
        int up = calculateSum(grid, dp, i - 1, j);
        int left = calculateSum(grid, dp, i, j - 1);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();    
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return calculateSum(grid, dp, n - 1, m - 1);
    }
};