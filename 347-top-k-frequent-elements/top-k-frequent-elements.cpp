class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num] ++;
        }

        // Converting into Priority Queue : 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min - heap
        for (auto &p : freq){
            pq.push({p.second, p.first});
            if (pq.size() > k){
                pq.pop();
            }
        }

        // Popping the top k frequent elements : 
        vector<int> res;
        while (!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};