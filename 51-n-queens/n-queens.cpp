class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> board(n, 0);
        backtrack(n, board, 0);
        return res;
    }


    vector<vector<string>> res;
    void backtrack(int n, vector<int>& board, int row) {
        // if we reach n th row, we succcessfully placed n queens at 0 - n-1 rows
        if (row == n) {
            res.push_back(generateBoard(board));
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (canPlace(board, row, col)) {
                board[row] |= (1 << col);  // add bit
                backtrack(n, board, row + 1);
                board[row] &= ~(1 << col);  // remove bit
            }
        }
    }

    bool canPlace(const vector<int>& board, int x, int y) {
        // check cols above
        for (int r = x - 1; r >= 0; -- r) {
            if ((board[r] & (1 << y)) > 0) return false;
        }

        // check left-up diagonal
        for (int r = x - 1, c = y - 1; r >= 0 && c >= 0; --r, --c) {
            if ((board[r] & (1 << c)) > 0) return false;
        }


        // check right-up diagonal
        for (int r = x - 1, c = y + 1; r >= 0 && c < board.size(); --r, ++c) {
            if ((board[r] & (1 << c)) > 0) return false;
        }

        return true;    
    }

    vector<string> generateBoard(const vector<int>& board) {
        vector<string> path;
        for (int i = 0; i < board.size(); ++i) {
            string str = "";
            for (int j = 0; j < board.size(); ++j) {
                if ((board[i] & (1 << j)) > 0) str += 'Q';
                else str += '.';
            }
            path.push_back(str);
        }
        return path;
    }
};