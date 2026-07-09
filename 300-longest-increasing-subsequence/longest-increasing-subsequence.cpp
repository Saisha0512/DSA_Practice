class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;

        for (int i = 0; i < n; i ++){
            int el = nums[i];
            int len = upper_bound(dp.begin(), dp.end(), el) - dp.begin();

            if (dp[len - 1] < el && el < dp[len]){
                dp[len] = el;
            }
        }

        int len = 0;
        for (int i = 1; i <= n; i ++){
            if (dp[i] != INT_MAX){
                len = i;
            }
        }

        return len;
    }
};