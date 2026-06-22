class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int l = 0, r = n - 1;
        vector<int> res(n, -1);

        // adding all the elements less than pivot in the start
        for (int i = 0; i < n; i ++){
            if (nums[i] < pivot){
                res[l ++] = nums[i];
            }
        }

        // adding all the elements greater than pivot in the end
        for (int j = n - 1; j >= 0; j --){
            if (nums[j] > pivot){
                res[r --] = nums[j];
            }
        }

        // filling all the intermediate empty positions with pivot
        while (l <= r){
            res[l ++] = pivot;
        }

        return res;
    }
};