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
    void addSum(TreeNode *root, int currlev, unordered_map<int, int> &m){
        // Base Case : 
        if (root == NULL){
            return;
        }

        // Recursive Case : 
        m[currlev] += root -> val;
        
        addSum(root -> left, currlev + 1, m);
        addSum(root -> right, currlev + 1, m);
    }

public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL){
            return 0;
        }

        unordered_map<int, int> m; // {Level No, Sum}
        addSum(root, 1, m);

        int maxlev = 1, maxsum = INT_MIN;
        for (auto &p : m){
            if (p.second > maxsum || (p.second == maxsum && p.first < maxlev)){
                maxlev = p.first;
                maxsum = p.second;
            }
        }

        return maxlev;
    }
};