// BOTTOM - UP APPROACH : 
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);

        // base cases
        dp[0] = 1; // by staying at the ground itself
        dp[1] = 1; // by climbing one stair

        // bottom up loop
        for (int i = 2; i <= n; i ++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};