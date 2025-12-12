class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minrow(n + 1, INT_MAX);
        vector<int> maxrow(n + 1, INT_MIN);
        vector<int> mincol(n + 1, INT_MAX);
        vector<int> maxcol(n + 1, INT_MIN);

        for (auto &building : buildings){
            int x = building[0], y = building[1];

            // Updating the mincol & maxcol for this particular x coord : 
            mincol[x] = min(mincol[x], y);
            maxcol[x] = max(maxcol[x], y);

            // Updating the minrow & maxrow for this partcular y coord : 
            minrow[y] = min(minrow[y], x);
            maxrow[y] = max(maxrow[y], x);
        }

        // Counting the no of safe buildings : 
        int cnt = 0;
        for (auto &b : buildings){
            int x = b[0], y = b[1];

            // Checking the conditions : 
            if (x > minrow[y] && x < maxrow[y] && y > mincol[x] && y < maxcol[x]){
                cnt ++;
            }
        }

        return cnt;
    }
};