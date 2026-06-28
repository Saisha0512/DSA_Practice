class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int max_sum = INT_MIN, curr_sum = 0;
        for (int i = 0; i < n; i ++){
            // adding the current value to the sum
            curr_sum += nums[i];
            max_sum = max(max_sum, curr_sum);

            // checking if the curr_sum is negative
            if (curr_sum < 0){
                curr_sum = 0; // so that the subarrays with larger sums are also considered in the answer, the one starting from (i + 1)th index or further
            }
        }

        return max_sum;
    }
};