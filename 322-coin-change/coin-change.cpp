// BOTTOM - UP APPROACH : 
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt + 1, amt + 1);

        // Base Case : 
        dp[0] = 0;

        // Iterate through all the amounts possible : 
        for (int i = 1; i <= amt; i ++){
            for (int coin : coins){
                if (i >= coin){
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return ((dp[amt] > amt)? -1 : dp[amt]);
    }
};