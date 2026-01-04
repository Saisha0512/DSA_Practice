class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                // Base Case : 
                if (i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = ((i > 0)? dp[i - 1][j] : 0) + ((j > 0)? dp[i][j - 1] : 0);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};