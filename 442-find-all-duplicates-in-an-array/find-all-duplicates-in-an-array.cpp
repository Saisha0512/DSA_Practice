class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i ++){
            int idx = abs(nums[i]);

            if (nums[idx - 1] < 0){
                res.push_back(idx);
            }
            else {
                // we mark the idx = abs(nums[i]) number as visited by negating the number present at idx - 1 index
                nums[idx - 1] *= -1;
            }
        }

        return res;
    }
};