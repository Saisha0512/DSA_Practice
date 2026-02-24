class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        set<int> res;
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num] ++;

            if (freq[num] > n / 3){
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};