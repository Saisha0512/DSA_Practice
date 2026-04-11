class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i ++){
            m[nums[i]].push_back(i);
        }

        int minsum = INT_MAX;
        for (auto &p : m){
            int num = p.first;
            vector<int> idx = p.second;

            if (idx.size() < 3){
                continue;
            }
            
            for (int i = 0; i < idx.size() - 2; i ++){
                int a = idx[i], b = idx[i + 1], c = idx[i + 2];
                int curr = 2 * (c - a);

                minsum = min(minsum, curr);
            }
        }

        return (minsum == INT_MAX)? -1 : minsum;
    }
};