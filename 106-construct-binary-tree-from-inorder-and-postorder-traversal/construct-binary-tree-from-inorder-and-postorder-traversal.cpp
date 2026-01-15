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
    TreeNode* construct(vector<int> &in, vector<int> &post, int s, int e, int &i){
        // Base Case : 
        if (s > e || i < 0){
            return NULL;
        }

        // Recursive Case : 
        int idx = -1;
        for (int j = s; j <= e; j ++){
            if (post[i] == in[j]){
                idx = j;
                break;
            }
        }

        TreeNode *root = new TreeNode(post[i --]);
        root -> right = construct(in, post, idx + 1, e, i);
        root -> left = construct(in, post, s, idx - 1, i);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int i = n - 1;
        return construct(inorder, postorder, 0, n - 1, i);
    }
};