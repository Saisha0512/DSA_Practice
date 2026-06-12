// BOTTOM - UP APPROACH : 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp initialization
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        // dp[i][j] = max profit starting from the ith day till the last day, where j tells the status of the transaction
        // j == 0 -> ready to buy the stock
        // j == 1 -> we can only sell the stock, ongoing transaction

        // bottom up loop
        for (int i = n - 1; i >= 0; i --){
            for (int j = 0; j < 2; j ++){
                // case 1 : skip the current day
                int op1 = dp[i + 1][j];

                // case 2 : buy or sell stock on the current day
                int op2 = INT_MIN;
                if (j == 0){ // buy
                    op2 = -prices[i] + dp[i + 1][1]; // ongoing transaction
                }
                else { // sell
                    op2 = prices[i] + dp[i + 2][0]; // adding 1 for the cooldown period
                }

                dp[i][j] = max(op1, op2);
            }
        }

        return dp[0][0];
    }
};