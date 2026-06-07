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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*> m;
        unordered_map<TreeNode*, TreeNode*> p;

        // iterating over all the descriptions
        for (auto &d : desc){
            int parent = d[0], child = d[1], isleft = d[2];
            TreeNode *newnode;
            if (m.find(child) == m.end()){
                m[child] = new TreeNode(child);
            }
            newnode = m[child];
            m[child] = newnode;
            
            // if the parent is not present, we create it and add it in the tree & maps
            TreeNode *par = NULL;
            if (m.find(parent) == m.end()){
                par = new TreeNode(parent);
                m[parent] = par;
                p[par] = NULL;
            }

            // left child
            if (isleft){
                m[parent] -> left = newnode;
                p[newnode] = m[parent];
            }
            // right child
            else {
                m[parent] -> right = newnode;
                p[newnode] = m[parent];
            }
        }

        // iterating over all the nodes to find the node who doesn't have a parent
        for (auto &it : p){
            if (it.second == NULL){
                return it.first;
            }
        }

        return NULL;
    }
};