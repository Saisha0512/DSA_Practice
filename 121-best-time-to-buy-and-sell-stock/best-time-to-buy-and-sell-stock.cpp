// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = max profit obtained considering days from 0 to i

    int profit(vector<int> &prices, int i, int minbuy){
        // base case
        if (i == prices.size()){
            return 0;
        }

        // check dp
        if (dp[i] != -1){
            return dp[i];
        }

        // recursive case
        // update the minimum buying price
        minbuy = min(minbuy, prices[i]);

        // case 1 : skip selling stocks today
        int op1 = profit(prices, i + 1, minbuy);

        // case 2 : selling the stocks today
        int op2 = prices[i] - minbuy;

        return dp[i] = max(op1, op2);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, -1);

        return profit(prices, 0, prices[0]);
    }
};