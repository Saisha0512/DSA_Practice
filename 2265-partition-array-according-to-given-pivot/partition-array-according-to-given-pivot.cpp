class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int i = 0, j = n - 1;
        vector<int> res(n, -1);

        while (i < n){
            // elements smaller than the picot in the start of the array
            if (nums[i] < pivot){
                res[l ++] = nums[i];
            }

            // elements greater than the pivot in the end of the array
            if (nums[j] > pivot){
                res[r --] = nums[j];
            }

            i ++; j --;
        }

        // filling the intermediate positions with pivot
        while (l <= r){
            res[l ++] = pivot;
        }

        return res;
    }
};