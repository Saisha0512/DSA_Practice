class Solution {
    int helper(int n, vector<int> &dp){
        // Base Case : 
        if (n == 1 || n == 2){
            return n;
        }

        // Recursive Case : 
        if (dp[n] != 0){
            return dp[n];
        }
        int ans = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n] = ans;
    }

public:
    int climbStairs(int n) {
        vector<int> dp(50, 0);
        return helper(n, dp);
    }
};