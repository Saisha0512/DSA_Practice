class Solution {
public:
    void dfs(TreeNode* root, int curr, int &total) {
        // Base Case : 
        if (root == NULL){
            return;
        }

        curr = curr * 2 + root->val;

        // Leaf Node : 
        if (!root->left && !root->right) {
            total += curr;
            return;
        }

        dfs(root->left, curr, total);
        dfs(root->right, curr, total);
    }

    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        dfs(root, 0, total);
        return total;
    }
};
