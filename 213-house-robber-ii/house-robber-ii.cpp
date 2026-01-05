class Solution {
    int recRobbery(vector<int> &nums, int i, int n, vector<int> &dp){
        // Base Case :
        if (i > n){
            return 0;
        }

        // Check DP : 
        if (dp[i] != -1){
            return dp[i];
        }

        // Recursive Case : 
        // Case 1 : Rob the current house & then move onto the (i + 2)th house : 
        int ans1 = nums[i] + recRobbery(nums, i + 2, n, dp);

        // Case 2 : Skipping the current house & moving onto the (i + 1)th house : 
        int ans2 = recRobbery(nums, i + 1, n, dp);

        // Returning the max of the two answers : 
        return dp[i] = max(ans1, ans2);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Base Cases : 
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return nums[0];
        }
        if (n == 2){
            return max(nums[0], nums[1]);
        }

        // DP Solution : 
        vector<int> dp0(n, -1), dp1(n, -1);

        // Case 1 : We start from the 0th house & then stop at the (n - 2)th house : 
        int ans0 = recRobbery(nums, 0, n - 2, dp0);

        // Case 2 : We start from the 1st house & then stop at the (n - 1)th house : 
        int ans1 = recRobbery(nums, 1, n - 1, dp1);

        return max(ans0, ans1);
    }
};