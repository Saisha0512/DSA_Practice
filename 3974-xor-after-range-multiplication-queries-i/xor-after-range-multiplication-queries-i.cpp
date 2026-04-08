class Solution {
    int mod = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<long long> temp;
        for (int num : nums){
            temp.push_back(num);
        }

        for (auto &q : queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];
            
            for (int i = l; i <= r; i += k){
                temp[i] = (temp[i] * v) % mod;
            }
        }

        int res = 0;
        for (int num : temp){
            res ^= num;
        }
        return res;
    }
};