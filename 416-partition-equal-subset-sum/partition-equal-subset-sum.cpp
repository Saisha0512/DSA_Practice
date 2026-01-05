// BOTTOM - UP APPROACH : 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto num : nums)   sum += num;

        if (sum % 2 != 0){
            return false;
        }

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base Cases : 
        // For all values of idx, if target == 0, then the ans will be true : 
        for (int i = 0; i < n; i ++){
            dp[i][0] = true;
        }
        // If idx == 0, then if target[0] = nums[0], the ans will be true : 
        if (nums[0] <= target){
            dp[0][nums[0]] = true;
        }

        // Bottom up loop : 
        for (int i = 1; i < n; i ++){
            for (int j = 1; j <= target; j ++){
                // Case 1 : If we dont take the current element, nums[i] into our subsequence : 
                bool notTake = dp[i - 1][j];
                
                // Case 2 : If we take the current element (nums[i]) into our subsequence : 
                bool take = false;
                if (j >= nums[i]){
                    take = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = notTake || take;
            }
        }

        return dp[n - 1][target];
    }
};