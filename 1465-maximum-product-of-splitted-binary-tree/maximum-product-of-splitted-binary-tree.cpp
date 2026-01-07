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
    long long mod = 1e9 + 7;
    long long treeSum(TreeNode *root){
        // Base Case : 
        if (root == NULL){
            return 0;
        }

        // Recursive Case : 
        root -> val += treeSum(root -> left) + treeSum(root -> right);
        return root -> val;
    }

public:
    int maxProduct(TreeNode* root) {
        long long total = treeSum(root);

        long long ans = LLONG_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            auto curr = q.front();
            q.pop();

            ans = max(ans, (total - curr -> val)*(curr -> val));

            if (curr -> left)   q.push(curr -> left);
            if (curr -> right)  q.push(curr -> right);
        }

        ans %= mod;
        return ans;
    }
};