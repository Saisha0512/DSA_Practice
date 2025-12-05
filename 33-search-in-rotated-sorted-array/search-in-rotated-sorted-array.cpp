class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high){
            int mid = (low + high)/2;

            // CASE 1 : We found the target element at the mid index : 
            if (nums[mid] == target){
                return mid;
            }

            // CASE 2 : If the left half of the current mid is strictly increasing : 
            if (nums[low] <= nums[mid]){
                if (nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // CASE 3 : If the right half of the current mid is strictly increasing : 
            else {
                if (nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};