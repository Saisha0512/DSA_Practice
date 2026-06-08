class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n = nums.size();

        vector<int> res(n, 0);
        int i = 0, j = n - 1; // pointers at nums
        int l = 0, r = n - 1; // pointers at res
        while (i < n && j >= 0){
            // smaller element
            if (nums[i] < p){
                res[l ++] = nums[i];
            }
            // greater element
            if (nums[j] > p){
                res[r --] = nums[j];
            }

            i ++;
            j --;
        }

        // adding the elements equal to pivot in the middle of the array
        while (l <= r){
            res[l ++] = p;
        }

        return res;
    }
};