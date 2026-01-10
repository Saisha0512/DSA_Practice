class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int currmax = nums[0], currmin = nums[0], maxprod = nums[0];
        for (int i = 1; i < n; i ++){
            if (nums[i] < 0){
                swap(currmax, currmin);
            }

            // Because on multiplying with a negative number : 
            // - currmin can become currmax
            // - currmax can become currmin

            currmax = max(nums[i], currmax*nums[i]);
            currmin = min(nums[i], currmin*nums[i]);
            maxprod = max(maxprod, currmax);
        }

        return maxprod;
    }
};