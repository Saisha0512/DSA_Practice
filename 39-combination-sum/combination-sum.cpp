class Solution {
    void check(vector<int> &nums, int target, int i, vector<int> &curr, vector<vector<int>> &res){
        // Base Case : 
        if (target == 0){
            res.push_back(curr);
            return;
        }
        if (i == nums.size()){
            return;
        }

        // Recursive Case : 
        // Case 1 : Not pick the current element
        check(nums, target, i + 1, curr, res);

        // Case 2 : Pick the current element
        if (target >= nums[i]){
            curr.push_back(nums[i]);
            check(nums, target - nums[i], i, curr, res);

            // Backtrack 
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> curr;
        vector<vector<int>> res;
        check(nums, target, 0, curr, res);

        return res;
    }
};

// TC : O(2^target)
// SC : Hypothetical SC, very difficult to calculate the most accurate one