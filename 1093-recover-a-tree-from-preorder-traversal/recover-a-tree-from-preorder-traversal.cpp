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
    TreeNode* recoverFromPreorder(string traversal) {
        map<int, TreeNode*> tree;
        int dash = 0, i = 0, n = traversal.size();
        while (i < n){
            while (i < n && traversal[i] == '-'){
                dash ++;
                i ++;
            }
            int val = 0;
            while (i < n && traversal[i] != '-'){
                val = val*10 + (traversal[i] - '0');
                i ++;
            }
            TreeNode *curr = new TreeNode(val);
            if (dash > 0){
                TreeNode *parent = tree[dash - 1];
                if (parent -> left == NULL){
                    parent -> left = curr;
                }
                else if (parent -> right == NULL){
                    parent -> right = curr;
                }
            }

            tree[dash] = curr;
            dash = 0;
        }

        return tree[0];
    }
};