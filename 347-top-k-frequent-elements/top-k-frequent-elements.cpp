class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num] ++;
        }

        // Converting into Priority Queue : 
        priority_queue<pair<int, int>> pq; // Max - heap
        for (auto &p : freq){
            pq.push({p.second, p.first});
        }

        // Popping the top k frequent elements : 
        vector<int> res;
        for (int i = 0; i < k; i ++){
            auto curr = pq.top();
            pq.pop();
            res.push_back(curr.second);
        }

        return res;
    }
};