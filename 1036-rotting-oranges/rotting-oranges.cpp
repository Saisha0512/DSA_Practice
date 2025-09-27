class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;
        vector<vector<int>> visited = grid;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (visited[i][j] == 2){
                    q.push({i, j});
                }
                else if (visited[i][j] == 1){
                    fresh ++;
                }
            }
        }

        if (fresh == 0){
            return 0;
        }
        else if (q.empty()){
            return -1;
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int mins = 0;
        while (!q.empty()){
            int size = q.size(); // Number of the current rotten oranges at this point of time
            while (size --){
                auto p = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = p.first + dx;
                    int j = p.second + dy;
                    if (i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 1){
                        visited[i][j] = 2;
                        fresh --;
                        q.push({i, j});
                    }
                }
            }
            mins ++;
        }

        if (fresh == 0){
            return mins - 1;
        }
        return -1;
    }
};