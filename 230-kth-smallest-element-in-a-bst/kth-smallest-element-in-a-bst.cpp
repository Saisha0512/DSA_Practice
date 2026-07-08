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
    int kthSmallest(TreeNode* root, int &k) {
        // base case
        if (!root){
            return -1;
        }

        // recursive case
        int ltree = kthSmallest(root -> left, k);
        if (ltree != -1){
            return ltree;
        }
        
        k --;
        if (k == 0){
            return root -> val;
        }

        return kthSmallest(root -> right, k);
    }
};