class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int lastx = points[0][0], lasty = points[0][1];

        int time = 0;
        for (int i = 1; i < n; i ++){
            int currx = points[i][0], curry = points[i][1];

            int diffx = abs(currx - lastx), diffy = abs(curry - lasty);
            int diagonal = min(diffx, diffy);
            time += diagonal;
            diffx -= diagonal;
            diffy -= diagonal;
            time += (diffx + diffy);

            lastx = currx;
            lasty = curry;
        }

        return time;
    }
};