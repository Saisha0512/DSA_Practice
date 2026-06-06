class Solution {
    vector<vector<int>> dp;
    // dp[i][j] = max profit that can be achieved if we start the from the ith index, with a boolean value j to determin the status of the last transaction made
    // j = true -> we can now buy stocs and start a new transaction
    // j = false -> we need to complete the previous transaction by selling the last bought stocks

    int stocks(vector<int> &prices, int i, bool buy, int fee){
        // base case
        // last stock is sold
        if (i == prices.size()){
            return 0;
        }

        // check dp
        if (dp[i][buy] != -1){
            return dp[i][buy];
        }

        // recursive case
        // case 1 : buying or selling the stocks at the current day
        int op1;
        if (buy == true){
            op1 = -prices[i] + stocks(prices, i + 1, false, fee);
        }
        else {
            op1 = prices[i] - fee + stocks(prices, i + 1, true, fee);
        }

        // case 2 : skip the current day
        int op2 = stocks(prices, i + 1, buy, fee);

        return dp[i][buy] = max(op1, op2);
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // dp intialization
        dp.resize(n, vector<int>(2, -1));

        return stocks(prices, 0, true, fee);
    }
};