class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> row1(n, 0), row0(n, 0), col1(m, 0), col0(m, 0);
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == 0){
                    row0[i] ++;
                    col0[j] ++;
                }
                else {
                    row1[i] ++;
                    col1[j] ++;
                }
            }
        }

        vector<vector<int>> diff(n, vector<int>(m, 0));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                diff[i][j] = row1[i] + col1[j] - row0[i] - col0[j];
            }
        }

        return diff;
    }
};