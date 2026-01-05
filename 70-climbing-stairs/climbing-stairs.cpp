class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int step = 2; step <= n; step ++){
            dp[step] = ((step - 1 >= 0)? dp[step - 1] : 0) + ((step - 2 >= 0)? dp[step - 2] : 0);
        }

        return dp[n];
    }
};