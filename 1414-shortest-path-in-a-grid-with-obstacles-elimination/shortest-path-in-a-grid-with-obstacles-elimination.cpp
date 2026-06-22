class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        // doing a bfs starting from (0, 0)th node
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
        queue<vector<int>> q; // {x, y, atmost k obstacles can be eliminated at this position}
        vis[0][0][k] = true;
        q.push({0, 0, k});

        int steps = 0;
        // bfs loop
        while (!q.empty()){
            int size = q.size();

            while (size --){
                auto curr = q.front();
                q.pop();
                int x = curr[0], y = curr[1], obs = curr[2];

                // check if the destination is reached
                if (x == n - 1 && y == m - 1){
                    return steps;
                }

                // at the current node we have 2 choices for each neighbor
                // iterating over the neighbors
                for (auto &[dx, dy] : dirs){
                    int i = x + dx, j = y + dy;

                    // check the boundary
                    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j][obs]){
                        continue;
                    }

                    // case 1 : no obstacle, then push the nbr directly
                    if (grid[i][j] == 0){
                        q.push({i, j, obs});
                        vis[i][j][obs] = true;
                    }

                    // case 2 : if obstacle is present at this nbr
                    if (grid[i][j] == 1 && obs > 0 && !vis[i][j][obs - 1]){
                        q.push({i, j, obs - 1});
                        vis[i][j][obs - 1] = true;
                    }
                }
            }

            steps ++;
        }

        return -1;
    }
};