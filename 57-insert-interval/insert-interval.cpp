class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // int newstart = newInterval[0], newend = newInterval[1];
        intervals.push_back(newInterval); // adding the new interval
        sort(intervals.begin(), intervals.end()); // sorting again
        int n = intervals.size();

        // int start, end;
        // vector<vector<int>> res;
        // // if the new interval starts & ends before the first interval
        // if (newend < intervals[0][0]){
        //     res.push_back(newInterval);
        //     res.insert(intervals.begin(), intervals.end(), res.end());
        //     return res;
        // }
        // // if the new interval overlaps with the first interval
        // else if (newstart >= intervals[0][0] || newend <= intervals[0][1]){
        //     start = min(intervals[0][0], newstart);
        //     end = max(intervals[0][1], newend);
        // }
        // // else we start merging the further intervals with the first interval
        // else {
        //     start = intervals[0][0];
        //     end = intervals[0][1];
        // }

        int start = intervals[0][0], end = intervals[0][1];
        // stack<int> last;
        vector<vector<int>> res;
        res.push_back({start, end});

        // iterating over the intervals ahead
        for (int i = 1; i < n; i ++){
            int s = intervals[i][0], e = intervals[i][1];

            // overlapping, hence merging the current interval with the last inserted interval
            if (s <= end){
                res.back()[0] = min(s, start);
                res.back()[1] = max(e, end);
            }
            // just adding this interval into res vector
            else if (s > start){
                res.push_back(intervals[i]);
            }

            // updating the start & end of the last  inserted interval
            start = res.back()[0];
            end = res.back()[1];
        }

        return res;
    }
};