class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Creating unordered map to find the appearance of the other element of the pair in further iterations : 
        unordered_map<int, int> m;
        for (int i = 0; i < n; i ++){
            // Checking for the element == target - nums[i] in the map : 
            if (m.find(target - nums[i]) != m.end()){
                return {m[target - nums[i]], i};
            }
            
            m[nums[i]] = i;
        }

        return {-1, -1};
    }
};