class Solution {
    int robHouse(vector<int> &nums, vector<int> &dp, int s, int e){
        // Base Case : 
        if (s > e){
            return 0;
        }

        // Checking the DP : 
        if (dp[s] != -1){
            return dp[s];
        }

        // Recursive Case : 
        // Case 1 : Leaving the current house & robbing the next house : 
        int skip = robHouse(nums, dp, s + 1, e);
        // Case 2 : Robbing the current house & leaving the next house : 
        int theft = robHouse(nums, dp, s + 2, e) + nums[s];
        
        return dp[s] = max(skip, theft);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Special Cases : 
        if (n == 0){
            return 0;
        }
        else if (n == 1){
            return nums[0];
        }
        else if (n == 2){
            return max(nums[0], nums[1]);
        }

        // Initializing the dp vectors : 
        // Case 1 : We start from the 0th index till the n - 2 th index
        vector<int> dp1(n, -1);
        int op1 = robHouse(nums, dp1, 0, n - 2);

        // Case 2 : We start from the 1st index till the n - 1 th index 
        vector<int> dp2(n, -1);
        int op2 = robHouse(nums, dp2, 1, n - 1);

        return max(op1, op2);
    }
};