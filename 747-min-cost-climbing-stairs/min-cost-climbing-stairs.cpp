// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = cost to climb reach the ith floor

    int climb(vector<int> &cost, int i){
        // base case
        if (i == 0 || i == 1){
            return 0;
        }

        // check dp
        if (dp[i] != -1){
            return dp[i];
        }

        // recursive case
        int op1 = climb(cost, i - 1) + cost[i - 1];
        int op2 = climb(cost, i - 2) + cost[i - 2];

        return dp[i] = min(op1, op2);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n + 1, -1);

        return climb(cost, n);
    }
};