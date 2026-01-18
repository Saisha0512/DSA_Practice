class Solution {
    static bool compare(const vector<int> &a, const vector<int> &b){
        if (a[1] == b[1]){
            return a[0] < b[0];
        }

        return a[1] < b[1];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), compare);

        int lastEnd = points[0][1];
        int arrows = 1;
        for (int i = 1; i < n; i ++){
            int start = points[i][0], end = points[i][1];
            if (start > lastEnd){
                lastEnd = end;
                arrows ++;
            }
        }
        
        return arrows;
    }
};