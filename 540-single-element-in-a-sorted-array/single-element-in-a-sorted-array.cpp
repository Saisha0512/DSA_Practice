class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int l = 0, h = n - 1;
        while (l <= h){
            int mid = (l + h)/2;

            int size = mid + 1;
            if (mid > 0 && nums[mid] == nums[mid - 1]){
                if (size % 2 == 0){
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
            else if (mid + 1 < n && nums[mid] == nums[mid + 1]){
                if (size % 2 != 0){
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
            else {
                return nums[mid];
            }
        }

        return -1;
    }
};