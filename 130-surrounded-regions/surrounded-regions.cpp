class Solution {
private : 
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, int x, int y){
    int n = board.size(), m = board[0].size();
    for (auto [dx, dy] : dirs){
        int i = x + dx, j = y + dy;
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || board[i][j] == 'X'){
            continue;
        }

        vis[i][j] = true;
        dfs(board, vis, i, j);
    }
}

public :
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false)); // To mark the visited O as true - these cannot be converted

        // TRAVERSING BOUNDARIES : 
        // Traversing the first & the last columns :  
        for (int i = 0; i < n; i ++){
            //  First Column : 
            if (board[i][0] == 'O' && !vis[i][0]){
                vis[i][0] = true;
                dfs(board, vis, i, 0);
            }
            // Last Column : 
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]){
                vis[i][m - 1] = true;
                dfs(board, vis, i, m - 1);
            }
        }

        // Traversing the first & the last row : 
        for (int i = 0; i < m; i ++){
            // First Row : 
            if (board[0][i] == 'O' && !vis[0][i]){
                vis[0][i] = true;
                dfs(board, vis, 0, i);
            }
            // Last Row : 
            if (board[n - 1][i] == 'O' && !vis[n - 1][i]){
                vis[n - 1][i] = true;
                dfs(board, vis, n - 1, i);
            }
        }

        // Converting the Os into X that are not visited : 
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};