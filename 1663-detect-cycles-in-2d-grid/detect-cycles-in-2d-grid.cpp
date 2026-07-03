class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool checkCycle(vector<vector<char>> &grid, vector<vector<int>> &status, int x, int y, int px, int py){
        int n = grid.size(), m = grid[0].size();
        status[x][y] = 1;
        char val = grid[x][y];

        // iterating over the adjcacent cells
        for (auto &[dx, dy] : dir){
            int i = x + dx, j = y + dy;

            if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != val){
                continue;
            }

            if (status[i][j] == 0){
                bool cycle = checkCycle(grid, status, i, j, x, y);

                if (cycle){
                    return true;
                }
            }
            else if (status[i][j] == 1 && (i != px || j != py)){
                return true; // cycle detected
            }
        }

        status[x][y] = 2;
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> status(n, vector<int>(m, 0));
        // 0 - unvisited, 1 - current path, 2 - completely visited path
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (status[i][j] == 0){
                    bool cycle = checkCycle(grid, status, i, j, -1, -1);

                    if (cycle){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};