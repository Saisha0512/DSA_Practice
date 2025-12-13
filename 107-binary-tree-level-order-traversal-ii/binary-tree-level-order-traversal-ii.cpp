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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL){
            return res;
        }
        vector<int> curr;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()){
            TreeNode *x = q.front();
            q.pop();

            if (x == NULL){
                res.push_back(curr);
                curr.clear();
                if (!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            else {
                curr.push_back(x -> val);
                if (x -> left){
                    q.push(x -> left);
                }
                if (x -> right){
                    q.push(x -> right);
                }
            }        
        }

        reverse(res.begin(), res.end());

        return res;
    }
};