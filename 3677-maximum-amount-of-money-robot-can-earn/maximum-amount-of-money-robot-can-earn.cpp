class Solution {
    long long takePath(vector<vector<int>> &coins, int i, int j, int neut, vector<vector<vector<long long>>> &dp){
        // Base Case : 
        if (i == coins.size() - 1 && j == coins[0].size() - 1){
            // Negative Coins & Neutralization
            if (coins[i][j] < 0 && neut > 0){
                return 0;
            }

            return coins[i][j];
        }

        // Boundary Base Case : 
        if (i >= coins.size() || j >= coins[0].size()){
            return LLONG_MIN/2;
        }

        // Check DP : 
        if (dp[i][j][neut] != LLONG_MIN){
            return dp[i][j][neut];
        }

        // Recursive Case : 
        long long ans = LLONG_MIN;
        // Case 1 : Positive coins 
        if (coins[i][j] >= 0){
            // Case A : Moving Right
            long long op1 = takePath(coins, i, j + 1, neut, dp);

            // Case B : Moving Down 
            long long op2 = takePath(coins, i + 1, j, neut, dp);

            long long best = max(op1, op2);
            if (best > LLONG_MIN/2){
                ans = coins[i][j] + best;
            }
        }

        // Case 2 : Negative Coins (Robbers)
        else {
            // Case i : Neutralization
            if (neut > 0){
                // Case A : Moving Right
                long long op1 = takePath(coins, i, j + 1, neut - 1, dp);

                // Case B : Moving Down 
                long long op2 = takePath(coins, i + 1, j, neut - 1, dp);

                long long best = max(op1, op2);
                if (best > LLONG_MIN/2){
                    ans = max(ans, best);
                }
            }
            
            // Case ii : No Neutralization
            // Case A : Moving Rigth
            long long op1 = takePath(coins, i, j + 1, neut, dp);

            // Case B : Moving Down 
            long long op2 = takePath(coins, i + 1, j, neut, dp);

            long long best = max(op1, op2);
            if (best > LLONG_MIN/2){
                ans = max(ans, coins[i][j] + best);
            }
        }

        return dp[i][j][neut] = ans;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (m, vector<long long>(3, LLONG_MIN)));
        return takePath(coins, 0, 0, 2, dp);
    }
};