class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right){
            int mid = (left + right)/2;

            // Target Found
            if (nums[mid] == target){
                return mid;
            }

            // If the left half is strictly increasing :
            if (nums[left] <= nums[mid]){
                if (nums[left] <= target && target <= nums[mid]){
                    right = mid -1;
                }
                else {
                    left = mid + 1;
                }
            }

            // If the right half is strictly increasing : 
            if (nums[mid] <= nums[right]){
                if (nums[mid] <= target && target <= nums[right]){
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};