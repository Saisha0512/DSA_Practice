// TOP - DOWN APPROACH : 
class Solution {
    long long checkCoins(vector<int>& coins, vector<int> &dp, long long amt){
        // Base Case : 
        if (amt == 0){
            return 0;
        }
        if (amt < 0){
            return -1;
        }

        // Check DP : 
        if (dp[amt] != -2){
            return dp[amt];
        }

        // Recursive Case : 
        int mincoins = INT_MAX;
        for (int coin : coins){
            if (coin > amt){
                break;
            }

            int res = checkCoins(coins, dp, amt - coin);
            if (res != -1){
                mincoins = min(mincoins, 1 + res);
            }
        }

        return dp[amt] = ((mincoins == INT_MAX)? -1 : mincoins);
    }

public:
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt + 1, -2);
        sort(coins.begin(), coins.end());

        return checkCoins(coins, dp, amt);
    }
};