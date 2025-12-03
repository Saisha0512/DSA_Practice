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
    int takePath(TreeNode *root, long long target, long long currsum, unordered_map<long long, int> &prefix){
        // Base Case : 
        if (root == NULL){
            return 0;
        }

        // Adding the current node to the current sum :
        currsum += root -> val;


        // Finding (currsum - target) in prefix map : 
        int cnt = 0;
        if (prefix.find(currsum - target) != prefix.end()){
            cnt += prefix[currsum - target];
        }

        // Adding the current prefix sum to the map : 
        prefix[currsum] ++;

        // Recursively calling the function on the children : 
        cnt += takePath(root -> left, target, currsum, prefix);
        cnt += takePath(root -> right, target, currsum, prefix);

        // Removing the prefix so that the prefix map can be used for other subtrees also : 
        prefix[currsum] --;

        return cnt;
    }

public:
    int pathSum(TreeNode* root, int target) {
        // Base Case : 
        if (root == NULL){
            return 0;
        }

        unordered_map<long long, int> prefix;
        prefix[0] = 1;
        int cnt = takePath(root, target, 0, prefix);

        return cnt;
    }
};