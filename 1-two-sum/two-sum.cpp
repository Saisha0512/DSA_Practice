class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> freq; // {Element, Index}
        for (int i = 0; i < n; i ++){
            // Checking if target - num is present in the array iterated earlier or not : 
            if (freq.find(target - nums[i]) != freq.end()){
                return {freq[target - nums[i]], i};
            }

            freq[nums[i]] = i;
        }

        return {-1, -1};
    }
};