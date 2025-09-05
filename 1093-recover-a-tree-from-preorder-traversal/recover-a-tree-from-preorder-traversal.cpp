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
        vector<pair<int, int>> arr; // {value, depth}
        int i = 0, n = traversal.size();
        while (i < n){
            int dash = 0;
            while (i < n && traversal[i] == '-'){
                dash ++;
                i ++;
            }
            int val = 0;
            while (i < n && traversal[i] != '-'){
                val = val*10 + (traversal[i] - '0');
                i ++;
            }

            arr.push_back({val, dash});
        }

        TreeNode *root = new TreeNode(arr[0].first);
        stack<TreeNode*> s;
        s.push(root);
        for (int i = 1; i < arr.size(); i ++){
            int depth = arr[i].second;
            TreeNode *node = new TreeNode(arr[i].first);
            while (s.size() > depth){
                s.pop();
            }
            TreeNode *parent = s.top();
            if (parent -> left == NULL){
                parent -> left = node;
            }
            else if (parent -> right == NULL){
                parent -> right = node;
            }

            s.push(node);
        }

        return root;
    }
};