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
    // {maxBranchSum, maxPathSum}
    pair<int, int> calculateSum(TreeNode *root){
        // Base Case :
        if (root == NULL){
            return {0, INT_MIN};
        }

        // Recursive Case : 
        auto ltree = calculateSum(root -> left);
        auto rtree = calculateSum(root -> right);

        int leftbranch = max(ltree.first, 0);
        int rightbranch = max(rtree.first, 0);

        int maxBranchSum = root -> val + max(leftbranch, rightbranch);
        int throughRoot = leftbranch + rightbranch + root -> val;
        int maxPathSum = max(throughRoot, max(ltree.second, rtree.second));

        return {maxBranchSum, maxPathSum};
    }

public:
    int maxPathSum(TreeNode* root) {
        auto res = calculateSum(root);

        return res.second;
    }
};