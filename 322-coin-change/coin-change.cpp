// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = min no of coins required to make the sum = i

    int change(vector<int> &coins, int amt){
        // base case
        if (amt == 0){
            return 0;
        }

        // check dp
        if (dp[amt] != -1){
            return dp[amt];
        }

        // recursive case
        int tempans = INT_MAX;
        // trying to form the amount from all the possible coin denominations
        for (int i = 0; i < coins.size(); i ++){
            if (coins[i] <= amt){
                // using the ith coint
                int currans = change(coins, amt - coins[i]);
                if (currans != INT_MAX){
                    tempans = min(tempans, currans + 1); // taking the minimum possible answer from all these options
                }
            }
        }

        return dp[amt] = tempans;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -1);
        int res = change(coins, amount);
        return (res == INT_MAX)? -1 : res;
    }
};