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
    map<int, vector<pair<int, int>>> mp; // {col, {row, val}}

    void insertNode(TreeNode *root, int col, int row){
        // base case
        if (!root){
            return;
        }

        // recursive case
        mp[col].push_back({row, root -> val});
        insertNode(root -> left, col - 1, row + 1);
        insertNode(root -> right, col + 1, row + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        insertNode(root, 0, 0);

        vector<vector<int>> res;
        // iterating over all the cols
        for (auto &p : mp){
            sort(p.second.begin(), p.second.end());

            vector<int> temp; // elements of the current col
            for (auto &q : p.second){
                temp.push_back(q.second);
            }

            res.push_back(temp);
        }

        return res;
    }
};