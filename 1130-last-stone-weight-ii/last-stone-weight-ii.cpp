class Solution {
    vector<vector<int>> dp;

    int subsetSum(vector<int> &stones, int idx, int target){
        // base case
        if (target == 0){
            return true;
        }
        if (idx == stones.size()){
            return false;
        }

        // check dp
        if (dp[idx][target] != -1){
            return dp[idx][target];
        }

        // recursive case
        // case 1 : not including the current element in the subset sum
        int op1 = subsetSum(stones, idx + 1, target);

        // case 2 : including the current element in the subset sum
        int op2 = 0;
        if (stones[idx] <= target){
            op2 = subsetSum(stones, idx + 1, target - stones[idx]);
        }

        return dp[idx][target] = (op1 | op2);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        dp.resize(n, vector<int>(sum + 1, -1));

        vector<int> possible_sums;
        for (int i = 0; i <= sum / 2; i ++){
            if (subsetSum(stones, 0, i)){
                possible_sums.push_back(i);
            }
        }

        // calculating the min difference
        int min_diff = INT_MAX;
        for (int num : possible_sums){
            min_diff = min(min_diff, sum - 2 * num);
        }

        return min_diff;
    }
};