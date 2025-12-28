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
    int getValue(TreeNode *root){
        // Base Case : 
        if (root == NULL){
            return 0;
        }

        return root -> val;
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        // Base Case : 
        if (root == NULL){
            return 0;
        }

        // Recursive Case :
        if (root -> val % 2 == 0){
            int ll = 0, lr = 0, rl = 0, rr = 0;
            if (root -> left){
                ll = getValue(root -> left -> left);
                lr = getValue(root -> left -> right);
            }
            if (root -> right){
                rl = getValue(root -> right -> left);
                rr = getValue(root -> right -> right);
            }
            

            return (ll + lr + rl + rr) + sumEvenGrandparent(root -> left) + sumEvenGrandparent(root -> right);
        }

        return sumEvenGrandparent(root -> left) + sumEvenGrandparent(root -> right);
    }
};