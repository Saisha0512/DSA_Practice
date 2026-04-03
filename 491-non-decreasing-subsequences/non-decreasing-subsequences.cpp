class Solution {
    void addSubseq(vector<int> &nums, int i, vector<int> &curr, vector<vector<int>> &res){
        // Base Case : 
        if (i == nums.size()){
            return;
        }

        // Recursive Case : 
        unordered_set<int> used;
        for (int j = i; j < nums.size(); j ++){
            // ALready used element : 
            if (used.find(nums[j]) != used.end()){
                continue;
            }

            // If the current element is less than the last entered element : 
            if (!curr.empty() && nums[j] < curr.back()){
                continue;
            }

            // Pushing the current element : 
            curr.push_back(nums[j]);
            used.insert(nums[j]);

            // Adding the current subseq in the res vector : 
            if (curr.size() >= 2){
                res.push_back(curr);
            }

            // Recursive Call : 
            addSubseq(nums, j + 1, curr, res);

            // Backtracking by removing the currently added element : 
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        addSubseq(nums, 0, curr, res);
        return res;
    }
};