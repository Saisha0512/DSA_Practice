class Solution {
    vector<vector<int>> dp;
    // dp[i][j] = number of paths to reach (i, j) from (0, 0)

    int countPath(int n, int m, int i, int j){
        // base case
        if (i == 0 && j == 0){
            return 1;
        }

        // check dp
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // recursive case
        int temp_ans = 0;
        // case 1 : coming to the current cell from up
        if (i - 1 >= 0){
            temp_ans += countPath(n, m, i - 1, j);
        }

        // case 2 : coming to the current cell from left
        if (j - 1 >= 0){
            temp_ans += countPath(n, m, i, j - 1);
        }

        return dp[i][j] = temp_ans;
    }

public:
    int uniquePaths(int n, int m) {
        dp.resize(n, vector<int>(m, -1));

        return countPath(n, m, n - 1, m - 1);
    }
};