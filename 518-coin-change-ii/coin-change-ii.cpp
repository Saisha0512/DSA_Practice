// TOP - DOWN APPROACH : 
class Solution {
    vector<vector<int>> dp;
    // dp[i][amt] = no of combinations that make up the sum = amt using the coins starting from the ith index in the given array

    int coinChange(vector<int> &coins, int amt, int i){
        // base case
        if (amt == 0){
            // one combination found
            return 1;
        }
        if (i == coins.size()){
            // out of bounds - not possible
            return 0;
        }

        // check dp
        if (dp[i][amt] != -1){
            return dp[i][amt];
        }

        // recursive case
        // case 1 : skip the current coin
        int op1 = coinChange(coins, amt, i + 1);

        // case 2 : take & add the current coin in the amount
        int op2 = 0;
        if (amt >= coins[i]){
            // as we have infinite no of coins for every denomination, we can start from the same index in the next call
            op2 = coinChange(coins, amt - coins[i], i);
        }

        return dp[i][amt] = op1 + op2;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // sorting the coins in increasing order
        sort(coins.begin(), coins.end());

        // dp initialization
        dp.resize(n, vector<int>(amount + 1, -1));

        return coinChange(coins, amount, 0);
    }
};