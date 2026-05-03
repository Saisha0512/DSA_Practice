// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;

    int checkSquare(int n){
        // base case
        if (n == 0 || n == 1){
            return n;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i ++){
            ans = min(ans, 1 + checkSquare(n - i * i));
        }

        return dp[n] = ans;
    }

public:
    int numSquares(int n) {
        dp.resize(n + 1, -1);

        return checkSquare(n);
    }
};