// TOP - DOWN APPROACH :
class Solution {
    vector<int> dp;

    int rob(vector<int> &nums, int i){
        // base case
        if (i == 0){
            return nums[i];
        }
        if (i == 1){ // you can either rob 0th or 1st house
            return max(nums[0], nums[1]);
        }

        // check dp
        if (dp[i] != -1){
            return dp[i];
        }

        // recursive case
        // case 1 : skip the current house
        int op1 = rob(nums, i - 1);

        // case 2 : robbing the current house & going for the (i - 2)th house
        int op2 = nums[i] + rob(nums, i - 2);

        return dp[i] = max(op1, op2);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);

        return rob(nums, n - 1);
    }
};