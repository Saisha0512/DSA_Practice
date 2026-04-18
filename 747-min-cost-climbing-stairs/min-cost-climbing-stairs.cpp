// BOTTOM - UP APPROACH : 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);

        // base cases : 
        dp[0] = 0; // starting point
        dp[1] = cost[0]; // need to climb one stair at the 0th index
        // dp[i] = cost to reach the ith stair

        // bottom - up loop : 
        for (int i = 2; i <= n; i ++){
            dp[i] = cost[i - 1] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n], dp[n - 1]);
    }
};