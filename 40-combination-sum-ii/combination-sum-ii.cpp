class Solution {
    void check(vector<int> &nums, int target, int start, vector<int> &curr, vector<vector<int>> &res){
        // Base Case : 
        if (target == 0){
            res.push_back(curr);
            return;
        }

        // Recursive Case : 
        // Trying out to use all the further elements at the current recursion level : 
        for (int i = start; i < nums.size(); i ++){
            // Repeatitive element
            if (i > start && nums[i] == nums[i - 1]){
                continue;
            }

            if (nums[i] > target){
                break;
            }

            // Pick the current element for the current recursion level : 
            curr.push_back(nums[i]);
            check(nums, target - nums[i], i + 1, curr, res);
            // Backtrack
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        vector<vector<int>> res;
        check(nums, target, 0, curr, res);

        return res;
    }
};

// TC : O(2^n)