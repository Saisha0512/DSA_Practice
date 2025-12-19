class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int currentSum = 0;
        int minLength = INT_MAX;

        while (right < nums.size()) {
            currentSum += nums[right];
            right++;

            while (currentSum >= target) {
                minLength = min(minLength, right - left);
                currentSum -= nums[left];
                left++;
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};