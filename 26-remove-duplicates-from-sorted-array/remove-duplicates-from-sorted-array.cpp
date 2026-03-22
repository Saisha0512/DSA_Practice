class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = 1;
        while (j < n){
            if (nums[j] != nums[i - 1]){
                swap(nums[j], nums[i ++]);
            }

            j ++;
        }

        return i;
    }
};