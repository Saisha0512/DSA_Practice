class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++){
            // First row : 
            if (board[i][0] == 'O'){
                vis[i][0] = true;
                q.push({i, 0});
            }
            // Last Row : 
            if (board[i][m - 1] == 'O'){
                vis[i][m - 1] = true;
                q.push({i, m - 1});
            }
        }
        for (int j = 0; j < m; j ++){
            // First row : 
            if (board[0][j] == 'O'){
                vis[0][j] = true;
                q.push({0, j});
            }
            // Last Row : 
            if (board[n - 1][j] == 'O'){
                vis[n - 1][j] = true;
                q.push({n - 1, j});
            }
        }

        // Iterating over all the neighbours - O to mark them that they cannot be converted to X : 
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;

                if (i >= 0 && j >= 0 && i < n && j < m && board[i][j] == 'O' && !vis[i][j]){
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        // Checking which Os can be converted to Xs : 
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};