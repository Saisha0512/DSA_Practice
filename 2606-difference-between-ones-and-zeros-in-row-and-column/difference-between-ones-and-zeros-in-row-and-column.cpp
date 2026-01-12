class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> row1(n, 0), col1(m, 0);
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == 1){
                    row1[i] ++;
                    col1[j] ++;
                }
            }
        }

        vector<vector<int>> diff(n, vector<int>(m, 0));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                diff[i][j] = row1[i] + col1[j] - (m - row1[i]) - (n - col1[j]);
            }
        }

        return diff;
    }
};