class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;

        do {
            res.insert(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return vector<vector<int>>(res.begin(), res.end());
    }
};