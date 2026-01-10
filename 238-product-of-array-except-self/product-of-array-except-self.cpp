class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftprod(n, 1), rightprod(n, 1);
        // Calculating the cumulative product from the left side of the array : 
        for (int i = 1; i < n; i ++){
            leftprod[i] = leftprod[i - 1] * nums[i - 1];
        }
        
        // Calculating the cumulative product from the right side of the array : 
        for (int i = n - 2; i >= 0; i --){
            rightprod[i] = rightprod[i + 1] * nums[i + 1];
        }

        // Calculating the product of array excpet self for each index : 
        for (int i = 0; i < n; i ++){
            leftprod[i] *= rightprod[i];
        }

        return leftprod;
    }
};