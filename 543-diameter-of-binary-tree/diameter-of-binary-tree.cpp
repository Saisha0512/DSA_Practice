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
    // {height, max_diameter}
    pair<int, int> check(TreeNode *root){
        // base case
        if (!root){
            return {-1, 0};
        }

        // recursive case
        auto ltree = check(root -> left);
        auto rtree = check(root -> right);
        int through_root = ltree.first + rtree.first + 2;

        int height = max(ltree.first, rtree.first) + 1;
        int max_diameter = max({ltree.second, rtree.second, through_root});
        
        return {height, max_diameter};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return check(root).second;
    }
};