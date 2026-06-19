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
public:
    int widthOfBinaryTree(TreeNode* root) {
        // base case
        if (root == NULL){
            return 0;
        }

        long long res = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()){
            int size = q.size();
            long long first, last;

            for (int i = 0; i < size; i ++){
                auto [curr_node, idx] = q.front();
                q.pop();

                if (i == 0){
                    first = idx;
                }
                if (i == size - 1){
                    last = idx;
                }

                // inserting the children into the queue
                if (curr_node -> left){
                    q.push({curr_node -> left, 2*idx + 1 - first});
                }
                if (curr_node -> right){
                    q.push({curr_node -> right, 2*idx + 2 - first});
                }
            }

            res = max(res, last - first + 1);
        }

        return res;
    }
};