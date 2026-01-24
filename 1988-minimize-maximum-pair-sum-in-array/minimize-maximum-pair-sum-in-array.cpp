class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        int maxSum = INT_MIN;
        while (l < r){
            int currSum = nums[l] + nums[r];
            maxSum = max(maxSum, currSum);

            l ++;
            r --;
        }

        return maxSum;
    }
};