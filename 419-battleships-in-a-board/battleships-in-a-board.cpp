class Solution {
    void dfs_traversal(vector<vector<char>> &board, vector<vector<bool>> &vis, int i, int j, bool horizontal){
        // marking the current node as visited
        vis[i][j] = true;

        // recursively calling for the right most horizontal cell or jut below vertical cell
        if (horizontal){
            if (j + 1 < board[0].size() && board[i][j + 1] == 'X' && !vis[i][j + 1]){
                dfs_traversal(board, vis, i, j + 1, horizontal);
            }
        }
        else {
            if (i + 1 < board.size() && board[i + 1][j] == 'X' && !vis[i + 1][j]){
                dfs_traversal(board, vis, i + 1, j, horizontal);
            }
        }
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        // iterating over all the nodes and checking for connected X cells to mark them as one battleship
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (!vis[i][j] && board[i][j] == 'X'){
                    // first checking in horizontal right direction
                    if (j + 1 < m && !vis[i][j + 1] && board[i][j + 1] == 'X'){
                        dfs_traversal(board, vis, i, j, true);
                    }

                    // else, checking for the vertically below cell or the single cell case
                    else {
                        dfs_traversal(board, vis, i, j, false);
                    }

                    cnt ++;
                }
            }
        }

        return cnt;
    }
};