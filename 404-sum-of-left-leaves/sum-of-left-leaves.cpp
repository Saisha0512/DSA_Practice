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
    int dfs(TreeNode *root, bool isleft){
        // Base Case : 
        if (root == NULL){
            return 0;
        }

        // Recursive Case : 
        if (isleft && !root -> left && !root -> right){
            return root -> val;
        }

        return dfs(root -> left, true) + dfs(root -> right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        // Base Case : 
        if (root == NULL){
            return 0;
        }
        
        return dfs(root, false);
    }
};