/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mp; // {original node, deep copy}
public:
    Node* cloneGraph(Node* node) {
        if (!node){
            return node;
        }

        // if the current node was already created
        if (mp.find(node) != mp.end()){
            return mp[node];
        }

        // creating a new node
        Node *new_node = new Node(node -> val);
        mp[node] = new_node;

        // iterating over the neighbors & creating them recursively
        for (auto nbr : node -> neighbors){
            new_node -> neighbors.push_back(cloneGraph(nbr));
        }

        return new_node;
    }
};