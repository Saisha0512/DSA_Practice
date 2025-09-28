class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int original = image[sr][sc]; // Original Color
        // If the starting pixel is the color itself : 
        if (original == color){
            return image;
        }

        // Otherwise : 
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 4 - Directions to move
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()){
            auto [x, y] = q.front();
            // Making the current pixel = col
            image[x][y] = color;
            q.pop();
            for (auto [dx, dy] : dirs){
                int i = x + dx, j = y + dy;
                if (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == original){ // The color of the current node should be same as the original color
                    q.push({i, j});
                }
            }
        }
        return image;
    }
};