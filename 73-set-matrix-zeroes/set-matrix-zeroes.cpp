class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> rows, cols;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (matrix[i][j] == 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        // Making all the elements in the valid rows = 0 : 
        for (int r : rows){
            for (int i = 0; i < m; i ++){
                matrix[r][i] = 0;
            }
        }

        // Making all the elements in the valid cols = 0 : 
        for (int c : cols){
            for (int i = 0; i < n; i ++){
                matrix[i][c] = 0;
            }
        }
    }
};