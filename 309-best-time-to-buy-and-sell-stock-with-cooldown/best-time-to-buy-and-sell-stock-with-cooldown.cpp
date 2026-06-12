// TOP - DOWN APPROACH : 
class Solution {
    vector<vector<int>> dp;
    // dp[i][j] = maximum profit starting from the ith day, where j tells the status of transaction
    // j = 0 -> you can buy now
    // j = 1 -> you can only sell or skip, as there is an ongoing transaction

    int stocks(vector<int> &prices, int i, int j){
        // base case
        if (i >= prices.size()){
            return 0;
        }

        // check dp
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // recursive case
        // case 1 : skip the current day
        int op1 = stocks(prices, i + 1, j);

        // case 2 : buy or sell on the current day
        int op2 = INT_MIN;
        if (j == 0){ // buy
            op2 = -prices[i] + stocks(prices, i + 1, 1);
        }
        else { // sell
            op2 = +prices[i] + stocks(prices, i + 2, 0); // cooldown period of one day added
        }

        return dp[i][j] = max(op1, op2);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp intialization
        dp.resize(n, vector<int>(2, -1));

        return stocks(prices, 0, 0);
    }
};