// BOTTOM - UP CODE : 
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int maxcost) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxcost + 1, INT_MIN)));
        // dp[i][j][k] = max score to crossing cell (i, j) by the exact cost k

        // dp initialization
        int cost = (grid[0][0] == 0)? 0 : 1;
        if (cost <= maxcost){
            dp[0][0][cost] = grid[0][0];
        }

        // bottom up loop
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                // base case
                if (i == 0 && j == 0){
                    continue; // already handled in intialization
                }

                int currval = grid[i][j];
                int currcost = (currval == 0)? 0 : 1;
                for (int k = 0; k <= maxcost; k ++){
                    // coming from up
                    if (i - 1 >= 0 && dp[i - 1][j][k] != INT_MIN){
                        int newcost = currcost + k;
                        if (newcost <= maxcost){
                            dp[i][j][newcost] = max(dp[i][j][newcost], dp[i - 1][j][k] + currval);
                        }
                    }

                    // coming from left
                    if (j - 1 >= 0 && dp[i][j - 1][k] != INT_MIN){
                        int newcost = currcost + k;
                        if (newcost <= maxcost){
                            dp[i][j][newcost] = max(dp[i][j][newcost], dp[i][j - 1][k] + currval);
                        }
                    }
                }
                
            }
        }

        // final answer 
        int ans = INT_MIN;
        for (int k = 0; k <= maxcost; k ++){
            ans = max(ans, dp[n - 1][m - 1][k]);
        }

        return (ans == INT_MIN)? -1 : ans;
    }
};