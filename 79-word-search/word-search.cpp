class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool checkWord(vector<vector<char>> &board, vector<vector<bool>> &vis, string word, int x, int y, int z){
        int n = board.size(), m = board[0].size();
        // base case
        if (z == word.size() - 1 && board[x][y] == word[z]){
            return true;
        }
        if (board[x][y] != word[z]){
            return false;
        }

        // recursive case
        vis[x][y] = true;

        for (auto &[dx, dy] : dir){
            int i = x + dx, j = y + dy;

            if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j]){
                continue;
            }

            bool subprob = checkWord(board, vis, word, i, j, z + 1);
            if (subprob){
                return true;
            }
        }

        vis[x][y] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (checkWord(board, vis, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};