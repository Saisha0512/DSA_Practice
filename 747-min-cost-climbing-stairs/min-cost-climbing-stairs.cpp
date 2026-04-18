class Solution {
    int climb(vector<int> &cost, int n, vector<int> &dp){
        // base case : 
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return cost[n - 1];
        }

        // check dp : 
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case : 
        // ans = min(coming from 1 step behind, coming from 2 steps behind)
        return dp[n] = cost[n - 1] + min(climb(cost, n - 1, dp), climb(cost, n - 2, dp));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(climb(cost, n, dp), climb(cost, n - 1, dp));
    }
};