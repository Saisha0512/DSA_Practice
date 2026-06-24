class Solution {
    const int mod = 1e9 + 7;
    vector<vector<vector<long long>>> dp;
    // dp[i][j][k] = no of possible attendance records with length n & absent days == j && ongoing consectuive late days == k

    long long create(int n, int a, int l){
        // base case
        if (n == 0){ // empty string
            return 1; // one string created
        }

        // check dp
        if (dp[n][a][l] != -1){
            return dp[n][a][l];
        }

        // recursive case
        // case 1 : P at the current day
        long long op1 = create(n - 1, a, 0); // 0 consecutive late days
        
        // case 2 : A at the current day
        long long op2 = 0;
        if (a == 0){
            op2 = create(n - 1, a + 1, 0);
        }

        // case 3 : L at the current day
        long long op3 = 0;
        if (l < 2){
            op3 = create(n - 1, a, l + 1);
        }

        return dp[n][a][l] = (op1 + op2 + op3) % mod;
    }

public:
    int checkRecord(int n) {
        // dp initialization
        dp.resize(n + 1, vector<vector<long long>>(2, vector<long long>(3, -1)));

        return create(n, 0, 0);
    }
};