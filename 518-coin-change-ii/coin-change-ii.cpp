// TOP - DOWN APPROACH : 
class Solution {
    vector<vector<int>> dp;
    // dp[i][amt] = number of combinations that make up the sum = amt using the coins startig from the ith index in the coins array

    int coinChange(vector<int> &coins, int amt, int i){
        // base case
        if (amt == 0){
            // one combination found
            return 1;
        }
        if (i == coins.size()){
            // out of bound - not possible
            return 0;
        }

        // check dp
        if (dp[i][amt] != -1){
            return dp[i][amt];
        }

        // recursive case
        int tempans = 0;
        // iterating over all the coins that can be used at this current level - starting from the coin at the current index i (as we have infinite no of coins for the same denomination)
        for (int j = i; j < coins.size(); j ++){
            // only using the coin if the amount is greater than or equal to the coin
            if (amt >= coins[j]){
                tempans += coinChange(coins, amt - coins[j], j);
            }
        }

        return dp[i][amt] = tempans;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // sorting the coins acc to the increasing order of their denominations
        sort(coins.begin(), coins.end());

        // dp initialization
        dp.resize(n, vector<int>(amount + 1, -1));

        return coinChange(coins, amount, 0);
    }
};