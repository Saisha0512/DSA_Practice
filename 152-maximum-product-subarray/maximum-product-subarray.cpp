class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int curr_min = nums[0], curr_max = nums[0], max_prod = nums[0];
        for (int i = 1; i < n; i ++){
            if (nums[i] < 0){
                swap(curr_min, curr_max);
            }

            curr_min = min(nums[i], curr_min * nums[i]);
            curr_max = max(nums[i], curr_max * nums[i]);
            max_prod = max(max_prod, curr_max);
        }

        return max_prod;
    }
};