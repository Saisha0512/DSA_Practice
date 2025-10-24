class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        // Find the rotten orange : 
        int fresh = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == 1){
                    fresh ++;
                }
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if (fresh == 0){
            return 0;
        }
        if (q.empty()){
            return -1;
        }

        int t = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()){
            int size = q.size();
            while (size --){
                auto [x , y] = q.front();
                q.pop();

                for (auto [dx, dy] : dirs){
                    int i = x + dx, j = y + dy;

                    if (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 1){
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh --;
                    }
                }
            }
            t ++;
        }

        if (fresh == 0){
            return t - 1;
        }
        return -1;
    }
};