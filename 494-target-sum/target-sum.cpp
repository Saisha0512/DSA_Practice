class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum){
            return 0;
        }
        if ((sum + target) % 2 != 0){
            return 0;
        }

        int subset = (sum + target) / 2;

        // dp initialization
        vector<vector<int>> dp(n + 1, vector<int>(subset + 1, 0));
        for (int i = 0; i <= n; i ++){
            for (int j = 0; j <= subset; j ++){
                if (i == 0){ // no element present in the subset
                    dp[i][j] = 0;
                }
                
                if (j == 0){ // sum == target
                    dp[i][j] = 1;
                }
            }
        }

        // bottom up loop
        for (int i = 1; i <= n; i ++){
            for (int j = 0; j <= subset; j ++){
                if (nums[i - 1] <= j){ // including the current element
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
                else { // not including the current element
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][subset];
    }
};