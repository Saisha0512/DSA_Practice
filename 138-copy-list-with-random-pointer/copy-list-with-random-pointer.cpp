/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL){
            return head;
        }
        unordered_map<Node*, Node*> memory;
        // Creating a copy of each node : 
        Node *temp = head;
        while (temp != NULL){
            memory[temp] = new Node(temp -> val);
            temp = temp -> next;
        }
        // Assigning next & random pointers : 
        temp = head;
        while (temp != NULL){
            memory[temp] -> next = memory[temp -> next];
            memory[temp] -> random = memory[temp -> random];
            temp = temp -> next;
        }
        return memory[head];
    }
};