class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return 1;
        }

        int min_idx = 0, max_idx = 0;
        for (int i = 0; i < n; i ++){
            // updating the min index
            if (nums[i] < nums[min_idx]){
                min_idx = i;
            }

            // updating the max index
            if (nums[i] > nums[max_idx]){
                max_idx = i;
            }
        }

        // case 1 : deleting both from left
        int op1 = min(min_idx, max_idx) + 1 + abs(min_idx - max_idx);
        // case 2 : deleting both from right
        int op2 = n - max(min_idx, max_idx) + abs(min_idx - max_idx);
        // case 3 : deleting from either sides
        int op3 = min(min_idx + 1, n - min_idx) + min(max_idx + 1, n - max_idx);

        return min(op1, min(op2, op3));
    }
};