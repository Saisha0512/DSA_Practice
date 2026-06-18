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
    int res = 0;

    struct NodeInfo {
        int min_val;
        int max_val;
        int sum;
        bool isBST;
    };

    NodeInfo check(TreeNode *root){
        // base case
        if (!root){
            return {INT_MAX, INT_MIN, 0, true}; // empty subtree
        }

        // recursive case
        auto ltree = check(root -> left);
        auto rtree = check(root -> right);
        // if this subtree is valid
        if (root -> val > ltree.max_val && root -> val < rtree.min_val && ltree.isBST && rtree.isBST){
            int curr_sum = root -> val + ltree.sum + rtree.sum;
            res = max(res, curr_sum);
            return {min(ltree.min_val, root -> val), max(rtree.max_val, root -> val), curr_sum, true};
        }

        return {INT_MAX, INT_MIN, 0, false}; // empty subtree
    }

public:
    int maxSumBST(TreeNode* root) {
        check(root);
        return res;
    }
};