// BOTTOM - UP APPROACH : 
class Solution {
public:
    int maxProfit(int l, vector<int>& prices) {
        int n = prices.size();
        const int neg = -1e9;

        // dp intialization
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(l + 1, vector<int>(l + 1, neg)));
        // dp base case
        for (int i = 0; i < n; i ++){
            dp[i][0][0] = 0;
        }
        for (int i = 0; i <= l; i ++){
            dp[n][i][i] = 0;
        }

        // bottom up loop
        for (int i = n - 1; i >= 0; i --){
            for (int j = 0; j <= l; j ++){
                for (int k = 1; k <= l; k ++){
                    // case 1 : buying the stocks at the current day
                    int op1 = INT_MIN;
                    if (j == k){
                        op1 = -prices[i] + dp[i + 1][j - 1][k];
                    }

                    // case 2 : selling the stocks at the current day
                    int op2 = INT_MIN;
                    if (j < k){
                        op2 = prices[i] + dp[i + 1][j][k - 1];
                    }

                    // case 3 : skipping the current day
                    int op3 = dp[i + 1][j][k];

                    dp[i][j][k] = max({op1, op2, op3});
                }
            }
        }

        return dp[0][l][l];
    }
};