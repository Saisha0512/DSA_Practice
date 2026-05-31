class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));

        // Base case:
        // There is exactly 1 way to make amount 0:
        // choose no coins.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {

                // Skip current coin
                dp[i][j] = dp[i - 1][j];

                // Take current coin
                if (j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};