class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> mp;
        int min_start = INT_MAX;
        for (auto &s : segments){
            int start = s[0], end = s[1], color = s[2];
            min_start = min(min_start, start);

            mp[start] += color;
            mp[end] -= color;
        }

        // going over the map & merging the overlapping segments
        vector<vector<long long>> res;
        vector<long long> prev;
        long long presum = 0;
        for (auto &[point, color] : mp){
            presum += color;
            if (point != min_start && prev[1] > 0){
                vector<long long> temp = {prev[0], point, prev[1]};
                res.push_back(temp);
            }

            prev = {point, presum};
        }
        
        return res;
    }
};