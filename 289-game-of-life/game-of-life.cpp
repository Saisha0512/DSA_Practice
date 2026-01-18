class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();

        vector<vector<int>> live(n, vector<int>(m, 0));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        
        // Checking the live nbrs of each cell : 
        for (int x = 0; x < n; x ++){
            for (int y = 0; y < m; y ++){

                for (auto [dx, dy] : dirs){
                    int i = x + dx, j = y + dy;
                    if (i < 0 || j < 0 || i >= n  || j >= m){
                        continue;
                    }

                    if (board[i][j] == 1){
                        live[x][y] ++;
                    }
                }
            }
        }

        // Checking the interaction of each cell : 
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (board[i][j] == 0){
                    if (live[i][j] == 3){
                        board[i][j] = 1;
                    }
                }
                else {
                    if (live[i][j] < 2){
                        board[i][j] = 0;
                    }
                    else if (live[i][j] == 2 || live[i][j] == 3){
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