class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Base Cases : 
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        // dp[i] = Max money that can be robbed from houses at the index : 0...i 
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int idx = 2; idx < n; idx ++){
            dp[idx] = max(dp[idx - 1], dp[idx - 2] + nums[idx]);
        }

        return dp[n - 1];
    }
};