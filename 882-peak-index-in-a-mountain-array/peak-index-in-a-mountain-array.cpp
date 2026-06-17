class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();

        int l = 0, h = n - 1;
        while (l < h){
            int mid = (l + h)/2;

            if (mid + 1 < n && nums[mid] > nums[mid + 1]){
                h = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};