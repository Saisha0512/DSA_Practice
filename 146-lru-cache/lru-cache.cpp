class Node {
public : 
    int key;
    int value;
    Node *prev, *next;

    Node(int k, int v){
        this -> key = k;
        this -> value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    int size;
    Node *head, *tail;
    unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
        size = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    void deleteNode(Node *node){
        Node *p = node -> prev, *n = node -> next;
        p -> next = n;
        n -> prev = p;
        mp.erase(node -> key);
    }
    
    void insertNode(Node *node){
        Node *n = head -> next;
        head -> next = node;
        node -> prev = head;
        node -> next = n;
        n -> prev = node;
        mp[node -> key] = node;
    }
    
    int get(int key) {
        if (mp.count(key)){
            Node *node = mp[key];
            deleteNode(node);
            insertNode(node);

            return node -> value;
        }

        return -1;
    }
    
    void put(int key, int val) {
        if (mp.count(key)){
            Node *node = mp[key];
            node -> value = val;
            deleteNode(node);
            insertNode(node);
        }
        else {
            if (mp.size() == size){
                // delete the last node of dll
                deleteNode(tail -> prev);
            }

            Node *new_node = new Node(key, val);
            insertNode(new_node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */