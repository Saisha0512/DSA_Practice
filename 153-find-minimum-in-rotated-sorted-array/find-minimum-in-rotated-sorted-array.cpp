class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right){
            int mid = (left + right)/2;

            // If the right half of the array is strictly increasing that means the smallest element wont be present there : 
            if (nums[mid] < nums[right]){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};