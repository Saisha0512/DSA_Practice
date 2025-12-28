class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxfreq = 0;
        for (auto num : nums){
            freq[num] ++;

            maxfreq = max(maxfreq, freq[num]);
        }

        vector<vector<int>> res(maxfreq);
        for (auto &p : freq){
            int el = p.first;
            int cnt = p.second;

            for (int i = 0; i < cnt; i ++){
                res[i].push_back(el);
            }
        }

        return res;
    }
};