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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        // base case
        if (root == NULL){
            return res;
        }

        // deque for bfs
        vector<int> curr_lev;
        deque<TreeNode*> dq;
        dq.push_back(root);
        dq.push_back(NULL);
        bool right = true; // traversing level left -> right

        // bfs loop
        while (!dq.empty()){
            // traversing left -> right in the level
            if (right){
                TreeNode *curr_node = dq.front();
                dq.pop_front();

                if (!curr_node){
                    // one level is traversed
                    res.push_back(curr_lev);
                    curr_lev.clear();
                    right = !right;

                    // next level is left to be traversed
                    if (!dq.empty()){
                        dq.push_front(NULL);
                    }
                }
                else {
                    curr_lev.push_back(curr_node -> val);

                    // pushing the children
                    if (curr_node -> left){
                        dq.push_back(curr_node -> left);
                    }
                    if (curr_node -> right){
                        dq.push_back(curr_node -> right);
                    }
                }
            }
            // traversing right -> left in the level
            else {
                TreeNode *curr_node = dq.back();
                dq.pop_back();

                if (!curr_node){
                    // one level is traversed
                    res.push_back(curr_lev);
                    curr_lev.clear();
                    right = !right;

                    if (!dq.empty()){
                        // all the children of the current level have been pushed
                        dq.push_back(NULL);
                    }
                }
                else {
                    curr_lev.push_back(curr_node -> val);

                    // pushing the children
                    if (curr_node -> right){
                        dq.push_front(curr_node -> right);
                    }
                    if (curr_node -> left){
                        dq.push_front(curr_node -> left);
                    }
                }
            }
        }

        return res;
    }
};