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
            int amt = INT_MIN;
            // Case 1 : We dont rob the current house, because the previous house was already robbed 
            if (idx - 1 >= 0){
                amt = max(amt, dp[idx - 1]);
            }

            // Case 2 : We rob the current house, because the (i - 2)th house was robbed 
            if (idx - 2 >= 0){
                amt = max(amt, dp[idx - 2] + nums[idx]);
            }

            dp[idx] = amt;
        }

        return dp[n - 1];
    }
};