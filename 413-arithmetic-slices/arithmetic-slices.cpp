// BOTTOM - UP APPROACH : 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2){
            return 0;
        }

        // dp intialization
        vector<int> dp(n, -1);
        // base cases
        dp[0] = dp[1] = 0;

        // bottom up loop
        for (int i = 2; i < n; i ++){
            // considering all the subarrays that ended till the previous index
            int tempans = dp[i - 1];

            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
                // computing all the arrays which can be extended till the current ith index from the previous index
                int prev = dp[i - 1] - dp[i - 2];

                // adding the no of subarrays which can be extended
                // and the one for the new 3-length window formed using the elements at the index i, i - 1 & i - 2
                tempans += prev + 1;
            }

            dp[i] = tempans;
        }

        return dp[n - 1];
    }
};