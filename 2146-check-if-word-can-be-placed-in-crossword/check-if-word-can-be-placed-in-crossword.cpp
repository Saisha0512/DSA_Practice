class Solution {
    bool check(vector<vector<char>> &board, string &word, int i, int j, int dx, int dy){
        int n = board.size(), m = board[0].size();

        // checking for the previous cell
        int pi = i - dx, pj = j - dy;
        if (pi >= 0 && pi < n && pj >= 0 && pj < m && board[pi][pj] != '#'){
            return false;
        }

        // starting to place chars in the given direction
        int x = i, y = j;
        for (int k = 0; k < word.size(); k ++){
            if (x < 0 || x >= n || y < 0 || y >= m){
                return false;
            }

            if (board[x][y] != ' ' && board[x][y] != word[k]){
                return false;
            }

            x += dx;
            y += dy;
        }

        // cell after the last character
        if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != '#'){
            return false;
        }

        return true;
    }

public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        // checking all the cells
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (board[i][j] == ' ' || board[i][j] == word[0]){
                    // checking if its possible to start the word from the current cell in any direction
                    for (auto &[dx, dy] : dirs){
                        if (check(board, word, i, j, dx, dy)){
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};