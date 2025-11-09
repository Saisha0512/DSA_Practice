class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        // Separating positive & negative elements in 2 separate arrays : 
        vector<int> neg, pos;
        for (int i = 0; i < n; i ++){
            if (nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else {
                pos.push_back(nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; i --){
            // Updating the positive elements at the even index : 
            if (i % 2 == 0){
                nums[i] = pos.back();
                pos.pop_back();
            }
            // Updating the negative elements at the odd index : 
            else {
                nums[i] = neg.back();
                neg.pop_back();
            }
        }

        return nums;
    }
};