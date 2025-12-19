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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool rev = false;
        while (!q.empty()){
            int size = q.size();
            vector<TreeNode*> temp(size);
            for (int i = 0; i < size; i ++){
                TreeNode *curr = q.front();
                q.pop();
                temp[i] = curr;

                // Adding the children of the current node : 
                if (curr -> left){
                    q.push(curr -> left);
                }
                if (curr -> right){
                    q.push(curr -> right);
                }

                // Reversing if rev is true : 
                if (rev && i >= size/2){
                    swap(temp[i] -> val, temp[size - 1 - i] -> val);
                }
            }

            rev = !rev;
        }

        return root;
    }
};