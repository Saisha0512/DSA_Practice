class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> dp = grid[0];
        // intializing first row of dp by taking prefix sum
        for (int i = 1; i < m; i ++){
            dp[i] += dp[i - 1];
        }

        for (int i = 1; i < n; i ++){
            vector<int> temp(m, INT_MAX);

            for (int j = 0; j < m; j ++){
                if (j > 0){
                    temp[j] = min(temp[j], grid[i][j] + temp[j - 1]);
                }

                temp[j] = min(temp[j], grid[i][j] + dp[j]);
            }

            dp = temp;
        }

        return dp[m - 1];
    }
};