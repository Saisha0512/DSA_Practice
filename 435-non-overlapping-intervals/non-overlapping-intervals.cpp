class Solution {
    static bool cmp(const vector<int> &a, const vector<int> &b){
        if (a[1] == b[1]){
            return a[0] < b[0];
        }

        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int cnt = 0;
        int lastEnd = intervals[0][1];
        for (int i = 1; i < n; i ++){
            int start = intervals[i][0];

            if (start < lastEnd){ 
                // As overlap is there, we remove the current interval : 
                cnt ++;
            }
            else {
                lastEnd = intervals[i][1];
            }
        }

        return cnt;
    }
};