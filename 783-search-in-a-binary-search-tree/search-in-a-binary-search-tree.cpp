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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // base case
        if (root == NULL || root -> val == val){
            return root;
        }

        // recursive case
        TreeNode *ltree = searchBST(root -> left, val);
        if (ltree != NULL){
            return ltree;
        }
        return searchBST(root -> right, val);
    }
};