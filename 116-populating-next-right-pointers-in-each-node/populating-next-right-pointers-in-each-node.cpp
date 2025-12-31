/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void addLevel(Node *root, int level, unordered_map<int, Node*> &m){
        // Base Case : 
        if (root == NULL){
            return;
        }

        // Recursive Case : 
        // Adding the current node to its level : 
        if (m.find(level) != m.end()){
            m[level] -> next = root;
            m[level] = root;
        }
        else {
            m[level] = root;
        }

        addLevel(root -> left, level + 1, m);
        addLevel(root -> right, level + 1, m);
    }

public:
    Node* connect(Node* root) {
        unordered_map<int, Node*> m;
        addLevel(root, 1, m);

        return root;
    }
};