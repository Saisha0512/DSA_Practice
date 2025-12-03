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
class BSTIterator {
        int idx = -1;
    vector<int> order;
    void inorder(TreeNode* root){
        // Base Case : 
        if (root == NULL){
            return;
        }

        // Recursive Case : 
        inorder(root -> left);
        order.push_back(root -> val);
        inorder(root -> right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return order[++ idx];
    }
    
    bool hasNext() {
        return (idx + 1 < order.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */