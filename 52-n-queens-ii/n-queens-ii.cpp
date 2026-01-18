class Solution {
public:
    int cnt = 0;

    void backtrack(int row, int n, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2){
        // Base Case : All queens are placed 
        if (row == n){
            cnt ++;
            return;
        }

        // Try placing queen in each column of current row : 
        for (int c = 0; c < n; c ++){
            // Checking if the column & diagonals are free : 
            if (col[c] == false && diag1[row - c + n - 1] == false && diag2[row + c] == false){
                // Place queen : 
                col[c] = true;
                diag1[row - c + n - 1] = true;
                diag2[row + c] = true;

                // Recursive Case for next row : 
                backtrack(row + 1, n, col, diag1, diag2);

                // Backtrack -> remvoing the queen : 
                col[c] = false;
                diag1[row - c + n - 1] = false;
                diag2[row + c] = false;
            }
        }
    }

    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2*n - 1, false); // Main - diagonal
        vector<bool> diag2(2*n - 1, false); // Anti - diagonal

        backtrack(0, n, col, diag1, diag2);
        return cnt;
    }
};