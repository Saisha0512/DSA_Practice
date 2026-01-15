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
    pair<int, int> checkSum(TreeNode *root){
        // Base Case : 
        if (root == NULL){
            return {0, INT_MIN};
        }

        // Recursive Case : 
        auto ltree = checkSum(root -> left);
        auto rtree = checkSum(root -> right);
        int leftBranch = max(0, ltree.first);
        int rightBranch = max(0, rtree.first);

        int branchSum = root -> val + max(leftBranch, rightBranch);
        int throughRoot = leftBranch + root -> val + rightBranch;
        int maxPathSum = max(throughRoot, max(ltree.second, rtree.second));

        return {branchSum, maxPathSum};
    }

public:
    int maxPathSum(TreeNode* root) {
        return checkSum(root).second;
    }
};