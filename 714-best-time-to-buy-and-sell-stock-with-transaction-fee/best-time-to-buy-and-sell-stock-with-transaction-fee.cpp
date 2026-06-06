class Solution {
    vector<vector<int>> dp;

    // buy = 1 -> can buy
    // buy = 0 -> currently holding a stock
    int stocks(vector<int>& prices, int i, int buy, int fee) {

        // base case
        if (i == prices.size()) {
            return 0;
        }

        // memoization
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        // case 1 : perform the action
        int op1;

        if (buy) {
            // buy stock
            op1 = -prices[i] +
                  stocks(prices, i + 1, 0, fee);
        }
        else {
            // sell stock
            op1 = prices[i] - fee +
                  stocks(prices, i + 1, 1, fee);
        }

        // case 2 : skip current day
        int op2 = stocks(prices, i + 1, buy, fee);

        return dp[i][buy] = max(op1, op2);
    }

public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        dp.resize(n, vector<int>(2, -1));

        return stocks(prices, 0, 1, fee);
    }
};