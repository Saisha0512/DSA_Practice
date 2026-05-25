// BOTTOM - UP APPROACH : 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // dp initialization
        vector<int> dp(amount + 1, -1);
        dp[0] = 0; // no coins needed to make the total sum = 0
        // dp[i] = minimum no of coins required to make the sum = i

        // bottom up loop
        for (int i = 1; i <= amount; i ++){
            int tempans = INT_MAX;

            // trying to use all the possible coins to make the current sum
            for (int j = 0; j < n; j ++){
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX){
                    tempans = min(tempans, 1 + dp[i - coins[j]]);
                }
            }

            dp[i] = tempans;
        }

        return (dp[amount] == INT_MAX)? -1 : dp[amount];
    }
};