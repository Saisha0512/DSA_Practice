class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num] ++;

            if (freq[num] > 1){
                return num;
            }
        }

        return -1;
    }
};