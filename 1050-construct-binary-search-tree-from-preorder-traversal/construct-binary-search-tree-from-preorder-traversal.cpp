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
    TreeNode* construct(vector<int> &preorder, vector<int> &inorder, int &i, int s, int e){
        // base case
        if (s > e){
            return NULL;
        }

        // node of this subtree will be preorder[i]
        TreeNode *root = new TreeNode(preorder[i ++]);

        int idx = -1;
        for (int i = s; i <= e; i ++){
            if (inorder[i] == root -> val){
                idx = i;
                break;
            }
        }

        // recursively constructing left subtree & right subtree
        root -> left = construct(preorder, inorder, i, s, idx - 1);
        root -> right = construct(preorder, inorder, i, idx + 1, e);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();

        // constructing inorder
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int i = 0;

        return construct(preorder, inorder, i, 0, n - 1);
    }
};