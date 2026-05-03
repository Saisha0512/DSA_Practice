// TOP - DOWN APPROACH : 
vector<int> dp(46, -1);
class Solution {
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
        int ans = climb(n - 1) + climb(n - 2);
        return dp[n] = ans;
    }

public:
    int climbStairs(int n) {
        return climb(n);
    }
};