// TOP - DOWN APPROACH :
class Solution {
    vector<int> dp;
    
    int climb(vector<int> &cost, int i){
        // base case
        if (i == 0 || i == 1){
            return cost[i];
        }

        // check dp 
        if (dp[i] != -1){
            return dp[i];
        }

        // recursive case
        // case 1 : coming from 1 step down
        int op1 = climb(cost, i - 1);

        // case 2 : coming from 2 steps down
        int op2 = climb(cost, i - 2);

        // result will be the minimum cost + cost of climbing the current step
        return dp[i] = cost[i] + min(op1, op2);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n, -1);

        // we can start from either 0th or 1st index
        return min(climb(cost, n - 1), climb(cost, n - 2));
    }
};