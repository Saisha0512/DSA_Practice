class Solution {
    int robHouses(vector<int> &nums, vector<int> &dp, int s, int e){
        // Base Case :
        if (s > e){
            return 0;
        }

        // Check DP : 
        if (dp[s] != -1){
            return dp[s];
        }

        // Recursive Case : 
        // Case 1 : If the current house is skipped & the next house is robbed : 
        int skip = robHouses(nums, dp, s + 1, e);

        // Case 2 : If the current house is robbed & the next house is skipped : 
        int current = nums[s] + robHouses(nums, dp, s + 2, e);

        return dp[s] = max(skip, current);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Special Cases : 
        if (n == 1){
            return nums[0];
        }
        if (n == 2){
            return max(nums[0], nums[1]);
        }

        vector<int> dp1(n, -1), dp2(n, -1);
        // Case 1 : Start robbing from the 0th indexed house till (n - 2)th house : 
        int op1 = robHouses(nums, dp1, 0, n - 2);
        // Case 2 : Start robbing from the 1th - indexed house till (n - 1)th house : 
        int op2 = robHouses(nums, dp2, 1, n - 1);

        return max(op1, op2);
    }
};