class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color){
            return image;
        }
        
        int n = image.size(), m = image[0].size();
        int org = image[sr][sc];
        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;
                if (i >= 0 && j >= 0 && i < n && j < m && image[i][j] == org){
                    image[i][j] = color;
                    q.push({i, j});
                }
            }
        }

        return image;
    }
};