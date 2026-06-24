class Solution {
    const int mod = 1e9 + 7;

public:
    int checkRecord(int n) {
        // dp initialization
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2, vector<long long>(3, 0)));
        // base cases - empty record
        for (int j = 0; j < 2; j ++){
            for (int k = 0; k < 3; k ++){
                dp[0][j][k] = 1;
            }
        }


        // dp[i][j][k] = no of possible attendance records of length i, such that no of As used till now == j && no of consecutive L in the end of the ongoing record == k

        for (int i = 1; i <= n; i ++){
            for (int j = 0; j < 2; j ++){
                for (int k = 0; k < 3; k ++){
                    // case 1 : P at the current day
                    long long op1 = dp[i - 1][j][0];

                    // case 2 : A at the current day
                    long long op2 = 0;
                    if (j == 0){
                        op2 = dp[i - 1][j + 1][0];
                    }

                    // case 3 : L at the current day
                    long long op3 = 0;
                    if (k < 2){
                        op3 = dp[i - 1][j][k + 1];
                    }

                    dp[i][j][k] = (op1 + op2 + op3) % mod;
                }
            }
        }

        return dp[n][0][0];
    }
};