class Solution {
    int recRobbery(vector<int> &nums, int i, vector<int> &dp){
        // Base Case : 
        if (i >= nums.size()){
            return 0;
        }

        // Check DP : 
        if (dp[i] != -1){
            return dp[i];
        }

        // Recursive Case : 
        // Case 1 : Robbing the current house & then moving to (i + 2)th house : 
        int ans1 = nums[i] + recRobbery(nums, i + 2, dp);

        // Case 2 : Leaving the current house & robbing the (i + 1)th house : 
        int ans2 = recRobbery(nums, i + 1, dp);

        return dp[i] = max(ans1, ans2);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recRobbery(nums, 0, dp);
    }
};