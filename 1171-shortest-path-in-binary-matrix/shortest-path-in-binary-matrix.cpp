class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1){
            return -1;
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {1, 1}, 
                                        {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int len = 1;

        while (!q.empty()){
            int size = q.size();
            while (size --){
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1){
                    return len;
                }

                for (auto [dx, dy] : dirs){
                    int i = x + dx, j = y + dy;

                    if (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0){
                        q.push({i, j});
                        grid[i][j] = 1;
                    }
                }
            }
            len ++;
        }

        return -1;
    }
};