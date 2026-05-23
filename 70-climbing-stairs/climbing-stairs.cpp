// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    int climb(int n){
        // base case
        if (n == 0 || n == 1){
            return 1;
        }

        // check dp 
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        dp[n] = climb(n - 1) + climb(n - 2);
        return dp[n];
    }

public:
    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return climb(n);
    }
};