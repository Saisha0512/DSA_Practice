class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num] ++;
        }

        int threshold = n / 3;
        vector<int> res;
        for (auto &p : freq){
            if (p.second > threshold){
                res.push_back(p.first);
            }
        }

        return res;
    }
};