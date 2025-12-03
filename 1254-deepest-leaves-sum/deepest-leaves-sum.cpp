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
    int deepestLeavesSum(TreeNode* root) {
        // Base Case : 
        if (root == NULL){
            return 0;
        }

        // Implementing BFS :
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();

            level = 0;
            while (size --){
                TreeNode *curr = q.front();
                q.pop();

                level += curr -> val;

                if (curr -> left){
                    q.push(curr -> left);
                }
                if (curr -> right){
                    q.push(curr -> right);
                }
            }
        }

        return level;
    }
};