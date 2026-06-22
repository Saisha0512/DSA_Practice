class Solution {
    int atMostKOdd(vector<int> &nums, int k){
        int n = nums.size();
        int left = 0, odd = 0, cnt = 0;

        for (int right = 0; right < n; right ++){
            // expanding the window
            odd += (nums[right] % 2);

            // contracting the window
            while (odd > k){
                odd -= (nums[left] % 2);
                left ++;
            }

            cnt += (right - left + 1); // adding the number of subarrays with atmost k odd nos in it
        }

        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKOdd(nums, k) - atMostKOdd(nums, k - 1);
    }
};