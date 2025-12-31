class DSU {
    vector<int> root, size;

public:
    DSU(int n) : root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }

    int find(int x) {
        if (root[x] != x)
            root[x] = find(root[x]);
        return root[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry)
            return;
        if (size[rx] > size[ry])
            swap(rx, ry);
        root[rx] = ry;
        size[ry] += size[rx];
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU dsu(row * col + 2);
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        for (int i = 0; i < row * col; i++) {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1;
            int id1 = r * col + c + 1;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 1) {
                    int id2 = nr * col + nc + 1;
                    dsu.unite(id1, id2);
                }
            }

            if (c == 0)
                dsu.unite(0, id1);
            if (c == col - 1)
                dsu.unite(row * col + 1, id1);

            if (dsu.find(0) == dsu.find(row * col + 1))
                return i;
        }
        return -1;
    }
};


// class Solution {
//     vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     bool dfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &vis){
//         // Base Case : 
//         if (x == grid.size() - 1){
//             return true;
//         }

//         // Recursive Case : 
//         // Visiting the current node : 
//         vis[x][y] = true;

//         for (auto [dx, dy] : dirs){
//             int i = x + dx, j = y + dy;
//             if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j] == 1){
//                 continue;
//             }

//             bool subprob = dfs(grid, i, j, vis);
//             if (subprob){
//                 return true;
//             }
//         }

//         // Backtrack : 
//         vis[x][y] = false;

//         return false;
//     }

//     bool checkPath(vector<vector<int>> &grid, int row, int col){
//         for (int i = 0; i < col; i ++){
//             if (grid[0][i] == 0){
//                 vector<vector<bool>> vis(row, vector<bool>(col, false));
//                 bool subprob = dfs(grid, 0, i, vis);
//                 if (subprob){
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }

// public:
//     int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
//         vector<vector<int>> grid(row, vector<int>(col, 0));

//         int last = -1;
//         for (int i = 0; i < cells.size(); i ++){
//             int x = cells[i][0], y = cells[i][1];
//             grid[x - 1][y - 1] = 1;
//             if (checkPath(grid, row, col)){
//                 last = i + 1;
//             }
//         }

//         return last;
//     }
// };