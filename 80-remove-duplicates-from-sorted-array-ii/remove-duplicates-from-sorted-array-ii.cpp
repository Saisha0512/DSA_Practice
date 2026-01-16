class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int start = 0;
        for (int end = 0; end < n; end ++){
            if (freq.find(nums[end]) == freq.end() || freq[nums[end]] < 2){
                freq[nums[end]] ++;
                swap(nums[start ++], nums[end]);
            }
        }

        return start;
    }
};