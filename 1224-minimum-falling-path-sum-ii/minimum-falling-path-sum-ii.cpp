class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // first row initialization
        for (int i = 0; i < n; i ++){
            dp[0][i] = grid[0][i];
        }

        // computing for the further next rows
        for (int i = 1; i < n; i ++){
            // iterating over the elements of the previous row
            for (int j = 0; j < n; j ++){
                int temp_ans = INT_MAX;

                for (int k = 0; k < n; k ++){
                    if (j == k){
                        continue;
                    }

                    temp_ans = min(temp_ans, dp[i - 1][k] + grid[i][j]);
                }

                dp[i][j] = temp_ans;
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};