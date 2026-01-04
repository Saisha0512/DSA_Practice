class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Filling the first row as it is : 
        for (int i = 0; i < n; i ++){
            dp[0][i] = mat[0][i];
        }

        // Iterating for the rest of the rows : 
        for (int i = 1; i < n; i ++){
            for (int j = 0; j < n; j ++){
                int ans = dp[i - 1][j];
                if (j > 0){
                    ans = min(ans, dp[i - 1][j - 1]);
                }
                if (j < n - 1){
                    ans = min(ans, dp[i - 1][j + 1]);
                }

                dp[i][j] = ans + mat[i][j];
            }
        }

        // Finding the minimum sum in the last row : 
        int minsum = INT_MAX;
        for (int i = 0; i < n; i ++){
            minsum = min(minsum, dp[n - 1][i]);
        }

        return minsum;
    }
};