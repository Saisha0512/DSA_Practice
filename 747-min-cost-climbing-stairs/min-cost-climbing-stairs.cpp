// BOTTOM - UP LOOP : 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // dp initialization
        vector<int> dp(n + 1, -1);
        // dp[i] = cost to reach the ith floor
        dp[0] = dp[1] = 0;

        for (int i = 2; i <= n; i ++){
            // climb from 1 floor down
            int op1 = dp[i - 1] + cost[i - 1];
            // climb from 2 floors down
            int op2 = dp[i - 2] + cost[i - 2];

            // taking the minimum of each of these paths
            dp[i] = min(op1, op2);
        }

        return dp[n];
    }
};