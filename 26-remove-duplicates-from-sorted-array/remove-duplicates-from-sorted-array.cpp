class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k = 0;
        int i = 0, j = 0; 
        while (i < n && j < n){
            if (nums[j] != nums[i]){
                i ++;
                swap(nums[i], nums[j]);
            }
            j ++;
        }
        return i + 1;
    }
};