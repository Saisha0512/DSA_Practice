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
    bool check(TreeNode *a, TreeNode *b){
        // Base Case : 
        if (!a && !b){
            return true;
        }
        if (!a || !b){
            return false;
        }

        // Recursive Case : 
        if (a -> val == b -> val && check(a -> left, b -> left) && check(a -> right, b -> right)){
            return true;
        }

        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base Case : 
        if (subRoot == NULL){
            return true;
        }
        if (root == NULL){
            return false;
        }

        // Recursive Case : 
        if (root -> val == subRoot -> val && check(root, subRoot)){
            return true;
        }

        bool ltree = isSubtree(root -> left, subRoot);
        bool rtree = isSubtree(root -> right, subRoot);

        return (ltree || rtree);
    }
};