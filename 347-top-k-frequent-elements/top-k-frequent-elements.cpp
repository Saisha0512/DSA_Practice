class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums)    freq[num] ++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &p : freq){
            int num = p.first, f = p.second;
            pq.push({f, num});
            
            while (pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty()){
            auto [f, num] = pq.top();
            pq.pop();
            res.push_back(num);
        }

        return res;
    }
};