class Solution {
    void addSubset(vector<int> &nums, int start, vector<int> &curr, vector<vector<int>> &res){
        // We insert every possible state at any point : 
        res.push_back(curr);

        // Recursive Case : 
        // Checking for all the elements that could be included at the current recursion level : 
        for (int i = start; i < nums.size(); i ++){
            if (i > start && nums[i] == nums[i - 1]){
                continue;
            }
            
            curr.push_back(nums[i]);
            addSubset(nums, i + 1, curr, res);
            // Backtrack : 
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> res;
        addSubset(nums, 0, curr, res);

        return res;
    }
};