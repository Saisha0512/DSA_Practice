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
    unordered_set<int> s;
public:
    bool findTarget(TreeNode* root, int k) {
        // base case
        if (!root){
            return false;
        }

        if (s.find(k - root -> val) != s.end()){
            return true;
        }

        // recurive case
        s.insert(root -> val);
        if (findTarget(root -> left, k)){
            return true;
        }
        return findTarget(root -> right, k);
    }
};