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
        // base case
        if (!a && !b){
            return true;
        }
        if (!a || !b || a -> val != b -> val){
            return false;
        }

        // recursive case
        if (a -> val == b -> val && check(a -> left, b -> right) && check(a -> right, b -> left)){
            return true;
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root -> left, root -> right);
    }
};