// TOP - DOWN APPROACH : 
class Solution {
    vector<int> dp;
    // dp[i] = no of arithmetic subarrays till the index i

    int slice(vector<int> &nums, int n){
        // base case
        if (n <= 1){
            return 0;
        }

        // check dp
        if (dp[n] != -1){
            return dp[n];
        }

        // recursive case
        // considering all the previously formed subarrays
        int tempans = slice(nums, n - 1);
        if (nums[n] - nums[n - 1] == nums[n - 1] - nums[n - 2]){
            // all the subarrays which end at the (n - 1)th index & can be extended forward
            int prev = slice(nums, n - 1) - slice(nums, n - 2);

            // so we add the no of all the arrays which can be extended forwards
            // and the 1 more 3-length array formed using the elements at n - 2, n - 1 & n
            tempans += prev + 1;
        }

        return dp[n] = tempans;
    }

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);

        return slice(nums, n - 1);
    }
};