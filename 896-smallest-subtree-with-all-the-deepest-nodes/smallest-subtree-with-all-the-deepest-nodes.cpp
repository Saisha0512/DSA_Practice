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
    pair<int, TreeNode*> checkLev(TreeNode *root, int currlev, int &maxlev, unordered_map<int, vector<TreeNode*>> &m){
        // Base Case : 
        if (root == NULL){
            return {-1, NULL};
        }

        if (currlev > maxlev){
            maxlev = currlev;
        }
        m[currlev].push_back(root);

        // Leaf node : 
        if (root -> left == NULL && root -> right == NULL){
            return {currlev, root};
        }

        // Recursive Case : 
        auto ltree = checkLev(root -> left, currlev + 1, maxlev, m);
        auto rtree = checkLev(root -> right, currlev + 1, maxlev, m);

        if (ltree.first == rtree.first){
            return {ltree.first, root};
        }
        else if (ltree.first > rtree.first){
            return ltree;
        }
        
        return rtree;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<int, vector<TreeNode*>> m;
        int maxlev = INT_MIN;

        auto ans = checkLev(root, 0, maxlev, m);
        return ans.second;
    }
};