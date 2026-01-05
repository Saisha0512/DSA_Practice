class Solution {
    int checkSum(vector<int> &nums, int idx, int target, vector<vector<int>> &dp){
        // Base Cases : 
        if (target == 0){
            return true;
        }
        if (idx == 0){
            return (nums[0] == target);
        }

        // Check DP : 
        if (dp[idx][target] != -1){
            return dp[idx][target];
        }

        // Recursive Case : 
        // Case 1 : Not taking the current element into the subsequence : 
        bool ans1 = checkSum(nums, idx - 1, target, dp);

        // Case 2 : Taking the current element into the subsequence : 
        bool ans2 = false;
        if (target >= nums[idx]){
            ans2 = checkSum(nums, idx - 1, target - nums[idx], dp);
        }

        return dp[idx][target] = (ans1 || ans2);
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (auto num : nums)   sum += num;
        if (sum % 2 != 0){
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        return checkSum(nums, n - 1, sum / 2, dp);
    }
};