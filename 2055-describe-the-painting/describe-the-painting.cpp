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
        auto it = mp.begin();
        long long start = it -> first, sum = it -> second;
        it ++;
        while (it != mp.end()){
            if (sum > 0){
                res.push_back({start, it -> first, sum});
            }

            start = it -> first;
            sum += it -> second;
            it ++;
        }
        
        return res;
    }
};