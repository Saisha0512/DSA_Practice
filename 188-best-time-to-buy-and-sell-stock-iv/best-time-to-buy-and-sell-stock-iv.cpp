// TOP - DOWN APPROACH : 
class Solution {
    vector<vector<vector<int>>> dp;
    // dp[i][j][k] = max profit you can achieve starting from index i, when you can buy the stocks atmost j times & sell them atmost k times

    int stocks(vector<int> &prices, int i, int buy, int sell){
        // base case
        if (buy == 0 && sell == 0){
            return 0;
        }
        if (i == prices.size()){
            return 0;
        }

        // check dp
        if (dp[i][buy][sell] != -1){
            return dp[i][buy][sell];
        }

        // recursive case
        // case 1 : buy the current stock
        int op1 = 0;
        if (buy == sell){ // previous stock has been sold already
            op1 = - prices[i] + stocks(prices, i + 1, buy - 1, sell);
        }

        // case 2 : sell the tock at the current day
        int op2 = 0;
        if (sell > buy){
            op2 = prices[i] + stocks(prices, i + 1, buy, sell - 1);
        }

        // case 3 : skip the current day
        int op3 = stocks(prices, i + 1, buy, sell);

        return dp[i][buy][sell] = max({op1, op2, op3});
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // dp intialization
        dp.resize(n, vector<vector<int>>(k + 1, vector<int>(k + 1, -1)));

        return stocks(prices, 0, k, k);
    }
};