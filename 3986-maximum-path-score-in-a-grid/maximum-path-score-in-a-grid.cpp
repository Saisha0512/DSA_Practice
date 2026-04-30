// TOP - DOWN CODE : 
class Solution {
    int checkPath(vector<vector<int>> &grid, int i, int j, int k, vector<vector<vector<int>>> &dp){
        int n = grid.size(), m = grid[0].size();

        // base case :
        if (i >= n || j >= m){
            return INT_MIN;
        }

        int val = grid[i][j];
        int cost = (val == 0)? 0 : 1;

        // checking the boundary of cost
        if (cost > k){
            return INT_MIN;
        }

        // bottom - right corner reached
        if (i == n - 1 && j == m - 1){
            return val;
        }

        // checking dp
        if (dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        // recursive case
        // going down
        int down = checkPath(grid, i + 1, j, k - cost, dp);

        // going right 
        int right = checkPath(grid, i, j + 1, k - cost, dp);

        int res = max(down, right);
        if (res == INT_MIN){
            return dp[i][j][k] = INT_MIN;
        }

        return dp[i][j][k] = res + val;
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        int res = checkPath(grid, 0, 0, k, dp);

        return (res == INT_MIN)? -1 : res;
    }
};