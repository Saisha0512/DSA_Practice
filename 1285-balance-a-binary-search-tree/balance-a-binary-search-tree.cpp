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
    void inorder(vector<int> &inord, TreeNode *root){
        // Base Case : 
        if (root == NULL){
            return;
        }

        // Recursive Case : 
        inorder(inord, root -> left);
        inord.push_back(root -> val);
        inorder(inord, root -> right);
    }

    TreeNode* build(int l, int r, vector<int> &inord){
        // Base Case : 
        if (l > r){
            return NULL;
        }

        // Recursive Case : 
        int mid = (l + r)/2;
        TreeNode *root = new TreeNode(inord[mid]);
        root -> left = build(l, mid - 1, inord);
        root -> right = build(mid + 1, r, inord);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inord;
        inorder(inord, root);
        return build(0, inord.size() - 1, inord);
    }
};