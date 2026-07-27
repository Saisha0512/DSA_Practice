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
    int max_sum = INT_MIN;

    int checkSum(TreeNode *root){
        // base case
        if (!root){
            return 0;
        }

        // recursive case
        int ltree = max(0, checkSum(root -> left)), rtree = max(0, checkSum(root -> right));
        max_sum = max(max_sum, ltree + root -> val + rtree);

        return max(ltree, rtree) + root -> val;
    }

public:
    int maxPathSum(TreeNode* root) {
        checkSum(root);

        return max_sum;
    }
};