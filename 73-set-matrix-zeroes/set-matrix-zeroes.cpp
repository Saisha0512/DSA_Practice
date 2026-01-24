class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        bool firstRow0 = false, firstCol0 = false;
        // Checking the first row : 
        for (int i = 0; i < m; i ++){
            if (matrix[0][i] == 0){
                firstRow0 = true;
            }
        }
        // Checking the first column : 
        for (int i = 0; i < n; i ++){
            if (matrix[i][0] == 0){
                firstCol0 = true;
            }
        }

        // Marking the cells which are 0 : 
        for (int i = 1; i < n; i ++){
            for (int j = 1; j < m; j ++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Updating the values in the matrix : 
        for (int row = 1; row < n; row ++){
            for (int col = 1; col < m; col ++){
                if (matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
        }

        // Updating the first row : 
        if (firstRow0){
            for (int i = 0; i < m; i ++){
                matrix[0][i] = 0;
            }
        }
        // Updating the first col : 
        if (firstCol0){
            for (int i = 0; i < n; i ++){
                matrix[i][0] = 0;
            }
        }
    }
};