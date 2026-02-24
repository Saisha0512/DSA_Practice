class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for (int i = 1; i < n; i ++){
            int s = intervals[i][0], e = intervals[i][1];

            if (s <= res.back()[1]){
                res.back()[1] = max(res.back()[1], e);
            }
            else {
                res.push_back({s, e});
            }
        }

        return res;
    }
};