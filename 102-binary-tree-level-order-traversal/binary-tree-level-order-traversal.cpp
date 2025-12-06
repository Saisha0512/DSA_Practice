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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        // Base Case : 
        if (root == NULL){
            return res;
        }

        // Initializing the queue : 
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;

        while (!q.empty()){
            auto curr = q.front();
            q.pop();

            // If NULL is encountered : 
            if (curr == NULL){
                res.push_back(temp);
                temp.clear();
                if (!q.empty()){
                    q.push(NULL);
                }
                continue;
            }

            temp.push_back(curr -> val); // Adding the data in the current level vector

            if (curr -> left){
                q.push(curr -> left);
            }
            if (curr -> right){
                q.push(curr -> right);
            }
        }

        return res;
    }
};