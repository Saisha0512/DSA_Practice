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
    void inorder(TreeNode *root, vector<int> &res, bool &found, int k){
        // Base Case : 
        if (root == NULL || found){
            return;
        }

        // Recursive Case : 
        inorder(root -> left, res, found, k);
        res.push_back(root -> val);
        if (res.size() == k){
            found = true;
            return;
        }
        inorder(root -> right, res, found, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        bool found = false;
        inorder(root, res, found, k);

        return res[k - 1];
    }
};