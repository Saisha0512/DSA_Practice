// BOTTOM UP DP APPROACH : 
class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base Case : 
        // There is only one way to reach (0, 0) cell : 
        dp[0][0] = 1;

        // Bottom - up DP Loop : 
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                // Case 1 : To reach the current cell, we can come from the upper cell
                if (i > 0){
                    dp[i][j] += dp[i - 1][j];
                }

                // Case 2 : To reach the current cell, we can come from the left cell
                if (j > 0){
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};