class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Calculating the maximum element row-wise & col-wise : 
        vector<int> row(n, INT_MIN);
        vector<int> col(m, INT_MIN);
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }

        // Checking how much could be increased for each element : 
        int cnt = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                cnt += abs(grid[i][j] - min(row[i], col[j]));
            }
        }

        return cnt;
    }
};