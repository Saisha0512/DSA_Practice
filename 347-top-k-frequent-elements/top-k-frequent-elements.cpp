class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int num : nums)    freq[num] ++;

        vector<vector<int>> temp(n + 1);
        for (auto &p : freq){
            temp[p.second].push_back(p.first);
        }

        // getting the top k most frequent elements
        vector<int> res;
        for (int i = n; i >= 0; i --){
            for (int num : temp[i]){
                res.push_back(num);

                if (res.size() == k){
                    return res;
                }
            }
        }

        return res;
    }
};