// TOP DOWN DP APPROACH : 
class Solution {
    int addPath(int i, int j, int n, int m, vector<vector<int>> &dp){
        // Base Case : Reached the destination cell
        if (i == n - 1 && j == m - 1){
            return 1;
        }

        // Check DP : 
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // Recursive Case : 
        // Case 1 : Moving right
        int right = 0;
        if (j + 1 < m){
            right = addPath(i, j + 1, n, m, dp);
        }

        // Case 2 : Moving down
        int down = 0;
        if (i + 1 < n){
            down = addPath(i + 1, j, n, m, dp);
        }

        dp[i][j] = (right + down);
        return dp[i][j];
    }

public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return addPath(0, 0, n, m, dp);
    }
};