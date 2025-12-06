class Solution {
public:
    // Implementing the Kadane's Algorithm for the maximum sum subarray : 
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currsum = 0, maxsum = INT_MIN;

        // Iterating for each element in the array & calculating the prefix sum : 
        for (int i = 0; i < n; i ++){
            currsum += nums[i];

            maxsum = max(maxsum, currsum); // Updating the maxsum

            // If the currsum becomes negative, then we make it equal to 0, so as to consider the subarrays possible by the positive elements after the current element : 
            if (currsum < 0){
                currsum = 0;
            }
        }

        return maxsum;
    }
};