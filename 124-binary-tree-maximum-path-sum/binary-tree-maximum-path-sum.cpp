/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // {max_branch_sum, max_path_sum}
    pair<int, int> check(TreeNode *root){
        // base case
        if (root == NULL){
            return {0, INT_MIN};
        }

        // recursive case
        auto ltree = check(root -> left);
        auto rtree = check(root -> right);

        int ans_through_root = max(0, ltree.first) + max(0, rtree.first) + root -> val;

        int max_branch_sum = max({ltree.first, rtree.first, 0}) + root -> val;
        int max_path_sum = max({ltree.second, rtree.second, ans_through_root});

        return {max_branch_sum, max_path_sum};
    }

public:
    int maxPathSum(TreeNode* root) {
        return check(root).second;
    }
};