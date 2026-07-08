class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool possible(vector<vector<int>> &grid, vector<vector<int>> &fire, int waiting){
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;

        int time = waiting;
        while (!q.empty()){
            int size = q.size();

            while (size --){
                auto [x, y] = q.front();
                q.pop();

                if (x == n - 1 && y == m - 1){
                    return true;
                }

                for (auto &[dx, dy] : dir){
                    int i = x + dx, j = y + dy;

                    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 2 || vis[i][j]){
                        continue;
                    }

                    int nbr_time = time + 1;
                    if (i == n - 1 && j == m - 1){
                        if (nbr_time > fire[i][j]){
                            continue;
                        }
                    }
                    else {
                        if (nbr_time >= fire[i][j]){
                            continue;
                        }
                    }

                    vis[i][j] = true;
                    q.push({i, j});
                }
            }

            time ++;
        }

        return false;
    }

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // storing the time till which fire can reach each cell
        vector<vector<int>> fire(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == 1){
                    q.push({i, j});
                    fire[i][j] = 0;
                }
            }
        }

        // running bfs
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (auto &[dx, dy] : dir){
                int i = x + dx, j = y + dy;

                if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 2){
                    continue;
                }

                if (fire[i][j] != INT_MAX){
                    continue;
                }

                fire[i][j] = fire[x][y] + 1;
                q.push({i, j});
            }
        }

        // binary search on waiting time
        int low = 0, high = 1e9;
        int ans = -1;

        while (low <= high){
            int mid = (low + high)/2;

            if (possible(grid, fire, mid)){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};