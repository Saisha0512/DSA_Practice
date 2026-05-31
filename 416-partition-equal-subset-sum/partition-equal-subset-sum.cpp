// TOP - DOWN APPROACH : 
class Solution {
    vector<vector<int>> dp;
    // dp[i][target] = is it possible to make a subset with sum == target using the elements till ith index

    int checkSum(vector<int> &nums, int i, int target){
        // base case
        if (target == 0){
            return true;
        }
        if (i == 0){
            return (nums[i] == target);
        }

        // check dp
        if (dp[i][target] != -1){
            return dp[i][target];
        }

        // recursive case
        // case 1 : not considering the current element
        bool op1 = checkSum(nums, i - 1, target);

        // case 2 : considering the current element in the subset forming
        bool op2 = false;
        if (target >= nums[i]){
            op2 = checkSum(nums, i - 1, target - nums[i]);
        }

        return dp[i][target] = (op1 || op2);
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // calculating the sum
        int sum = 0;
        for (int num : nums){
            sum += num;
        }

        // base case - if the sum is odd, not possible
        if (sum % 2 != 0){
            return false;
        }

        // dp initialization
        dp.resize(n, vector<int>(sum / 2 + 1, -1));

        // finding if it is possible to find a subset with sum = sum/2
        return checkSum(nums, n - 1, sum / 2);
    }
};