class Solution {
    void addPerm(vector<int> &nums, vector<int> &curr, vector<bool> &vis, vector<vector<int>> &res){
        int n = vis.size();
        // Base Case : 
        if (curr.size() == n){
            res.push_back(curr);
            return;
        }

        // Recursive Call : 
        for (int i = 0; i < n; i ++){
            if (!vis[i]){
                curr.push_back(nums[i]);
                vis[i] = true;
                // Recursive Call : 
                addPerm(nums, curr, vis, res);

                // Backtracking : 
                curr.pop_back();
                vis[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> vis(n, false);
        vector<int> curr;
        vector<vector<int>> res;
        addPerm(nums, curr, vis, res);

        return res;
    }
};

// TC : O(n x n!)
// SC : O(n)