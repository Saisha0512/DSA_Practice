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
    vector<int> res;

    void moveRight(TreeNode *root, int curr_lev, int &max_lev){
        // base case
        if (!root){
            return;
        }

        // recursive case
        if (curr_lev > max_lev){
            res.push_back(root -> val);
            max_lev = curr_lev;
        }

        moveRight(root -> right, curr_lev + 1, max_lev);
        moveRight(root -> left, curr_lev + 1, max_lev);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        int max_lev = -1;
        moveRight(root, 0, max_lev);

        return res;
    }
};