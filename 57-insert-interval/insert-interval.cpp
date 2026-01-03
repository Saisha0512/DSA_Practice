class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({newInterval[0], newInterval[1]});

        for (auto &i : intervals){
            pq.push({i[0], i[1]});
        }

        vector<vector<int>> res;

        // Initializing the last interval encountered : 
        auto [lastStart, lastEnd] = pq.top();
        pq.pop();

        while (!pq.empty()){
            auto [start, end] = pq.top();
            pq.pop();

            if (start > lastEnd){
                res.push_back({lastStart, lastEnd});
                lastStart = start;
                lastEnd = end;
            }
            else {
                lastEnd = max(lastEnd, end);
            }
        }
        res.push_back({lastStart, lastEnd});

        return res;
    }
};