class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i ++){
            pre[i] = pre[i - 1] + nums[i];
        }

        int min_sum = INT_MAX;
        // dealing with subarrays ending at ith position
        for (int i = 0; i < n; i ++){
            if (i - l + 1 < 0){
                continue;
            }

            for (int j = i - l + 1; j >= max(0, i - r + 1); j --){
                int curr_sum = pre[i] - ((j > 0)? pre[j - 1] : 0);

                if (curr_sum > 0){
                    min_sum = min(min_sum, curr_sum);
                }
            }
        }

        if (min_sum == INT_MAX){
            return -1;
        }

        return min_sum;
    }
};