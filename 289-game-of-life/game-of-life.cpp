class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();

        vector<vector<int>> pre(n, vector<int>(m, 0));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                pre[i][j] = board[i][j];
                if (i > 0){
                    pre[i][j] += pre[i - 1][j];
                }
                if (j > 0){
                    pre[i][j] += pre[i][j - 1];
                }
                if (i > 0 && j > 0){
                    pre[i][j] -= pre[i - 1][j - 1];
                }
            }
        }

        // Checking the interactions for each cell : 
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                int a = ((i > 0)? i - 1 : 0), b = ((j > 0)? j - 1 : 0);
                int c = ((i < n - 1)? i + 1 : n - 1), d = ((j < m - 1)? j + 1 : m - 1);
                int live = pre[c][d];
                if (a > 0){
                    live -= pre[a - 1][d];
                }
                if (b > 0){
                    live -= pre[c][b - 1];
                }
                if (a > 0 && b > 0){
                    live += pre[a - 1][b - 1];
                }

                if (board[i][j] == 0){
                    if (live == 3){
                        board[i][j] = 1;
                    }
                }
                else {
                    live --;
                    if (live == 2 || live == 3){
                        continue;
                    }
                    else {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};