class Solution {
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool dfs_traversal(vector<vector<char>> &grid, vector<vector<bool>> &vis, int x, int y, pair<int, int> par){
        int n = grid.size(), m = grid[0].size();

        // visiting the current node
        vis[x][y] = true;
        // curr_path.insert({x, y});

        // iterating over the neighbors
        for (auto &[dx, dy] : dirs){
            int i = x + dx, j = y + dy;

            if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != grid[x][y] || (i == par.first && j == par.second)){
                continue; // skip this neighbor
            }

            // // cycle detected
            // if (curr_path.find({i, j}) != curr_path.end()){
            //     return true;
            // }
            
            if (!vis[i][j]){
                bool subprob = dfs_traversal(grid, vis, i, j, {x, y});

                if (subprob){
                    return true;
                }
            }
            else if (vis[i][j] && (i != par.first || j == par.second)){
                return true; // visited node found which is not parent
            }
        }

        // backtrack
        // curr_path.erase({x, y});
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        // unordered_set<pair<int, int>> curr_path;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (!vis[i][j]){
                    bool cycle = dfs_traversal(grid, vis, i, j, {-1, -1});

                    if (cycle){
                        return true;
                    }
                }
            }
        }

        return false; // no cycle detected
    }
};