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
    unordered_map<Node*, Node*> mp;

public:
    Node* cloneGraph(Node* node) {
        // base case
        if (node == NULL){
            return node;
        }

        // checking if the node was already made
        if (mp.find(node) != mp.end()){
            return mp[node];
        }

        // recursive case
        // creating the new node of the current node
        Node *newnode = new Node(node -> val);
        mp[node] = newnode;
        // iterating over the neigbours & creating the deep copies
        for (auto nbr : node -> neighbors){
            newnode -> neighbors.push_back(cloneGraph(nbr));
        }

        return newnode;
    }
};