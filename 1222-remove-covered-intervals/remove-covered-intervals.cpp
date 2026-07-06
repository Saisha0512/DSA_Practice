class Solution {
    static bool compare(vector<int> &a, vector<int> &b){
        if (a[0] == b[0]){
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }

public:
    int removeCoveredIntervals(vector<vector<int>>& intv) {
        int n = intv.size();

        sort(intv.begin(), intv.end(), compare);
        
        int cnt = 0;
        int start = intv[0][0], end = intv[0][1];
        for (int i = 1; i < n; i ++){
            if (intv[i][0] >= start && end >= intv[i][1]){
                cnt ++;
            }
            else {
                start = intv[i][0];
                end = intv[i][1];
            }
        }

        return n - cnt;
    }
};