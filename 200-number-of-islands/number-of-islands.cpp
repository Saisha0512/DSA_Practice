class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4 - Directions

    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        // Marking the current node as visited : 
        vis[x][y] = true;

        // Iterating over the nbrs & calling the recursive dfs over non - visited nbrs : 
        for (auto [dx, dy] : dirs){
            int i = x + dx, j = y + dy;

            // Out of boundary cases + Water cases : 
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || vis[i][j]){
                continue;
            }

            dfs(i, j, grid, vis); // Recursive DFS Call 
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false)); // Visited or Unvisited Vector

        int cnt = 0;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, grid, vis);
                    cnt ++;
                }
            }
        }

        return cnt;
    }
};