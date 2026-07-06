class Solution {
    int res = INT_MIN;
    vector<vector<int>> dp;
    // dp[i][j] = maximum reachable value from (i, j)

    int checkCell(vector<vector<int>> &grid, int i, int j){
        int n = grid.size(), m = grid[0].size();

        // check dp
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // recursive case
        int temp_ans = grid[i][j];

        // case 1 : going down
        if (i + 1 < n){
            int down = checkCell(grid, i + 1, j);
            res = max(res, down - grid[i][j]); // max total score starting from (i, j)th cell
            temp_ans = max(temp_ans, down); // max value got from path going down
        }

        // case 2 : going right
        if (j + 1 < m){
            int right = checkCell(grid, i, j + 1);
            res = max(res, right - grid[i][j]);
            temp_ans = max(temp_ans, right);
        }

        return dp[i][j] = temp_ans;
    }

public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<int>(m, -1));
        
        // max total score = last value reached - first value started with
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                checkCell(grid, i, j);
            }
        }

        return res;
    }
};