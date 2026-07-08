class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prod(n, 1);
        for (int i = 1; i < n; i ++){
            prod[i] = prod[i - 1] * nums[i - 1];
        }

        int right = nums[n - 1];
        for (int i = n - 2; i >= 0; i --){
            prod[i] *= right;
            right *= nums[i];
        }

        return prod;
    }
};