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
    int idx;

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        idx = -1;
    }
    
    int next() {
        idx ++;
        return order[idx];
    }
    
    bool hasNext() {
        if (idx + 1 < order.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */