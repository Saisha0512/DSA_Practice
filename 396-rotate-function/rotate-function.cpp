class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        // initializing the first value - F(0)
        int sum = 0;
        for (int i = 0; i < n; i ++){
            dp[0] += (i * nums[i]);
            sum += nums[i];
        }

        int maxans = dp[0];
        // calculating for other values
        for (int i = 1; i < n; i ++){
            dp[i] = dp[i - 1] - sum + n * nums[i - 1];
            maxans = max(maxans, dp[i]);
        }

        return maxans;
    }
};