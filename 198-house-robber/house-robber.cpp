// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = maximum amount on robbering i houses

    int robbery(vector<int> &nums, int n){
        // base case
        if (n <= 0){
            return 0;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        // case 1 : skip the current house
        int op1 = robbery(nums, n - 1);

        // case 2 : rob the current house & move to (n - 2)th house
        int op2 = robbery(nums, n - 2) + nums[n - 1];

        return dp[n] = max(op1, op2);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n + 1, -1);

        return robbery(nums, n);
    }
};