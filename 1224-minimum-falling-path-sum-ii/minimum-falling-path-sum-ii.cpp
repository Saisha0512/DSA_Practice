class Solution {
    vector<vector<int>> dp;

    int minSum(vector<vector<int>> &grid, int x, int y){
        int n = grid.size();
        // base case
        if (x == 0){ // first row
            return grid[x][y];
        }

        // check dp
        if (dp[x][y] != -1){
            return dp[x][y];
        }

        // recursive case
        // we try using all the elements in the previous row
        int temp_ans = INT_MAX;
        for (int j = 0; j < n; j ++){
            if (y == j){
                continue;
            }

            int curr_ans = grid[x][y] + minSum(grid, x - 1, j);
            temp_ans = min(temp_ans, curr_ans);
        }

        return dp[x][y] = temp_ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        dp.resize(n, vector<int>(n, -1));

        // recursively calling the function for every element in the last row
        int res = INT_MAX;
        for (int j = 0; j < n; j ++){
            res = min(res, minSum(grid, n - 1, j));
        }

        return res;
    }
};