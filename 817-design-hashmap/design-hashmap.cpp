class Node {
public : 
    int key;
    int value;
    Node *next;

    Node (int k, int v){
        key = k;
        value = v;
        next = NULL;
    }

    Node (int k, int v, Node *n){
        key = k;
        value = v;
        next = n;
    }
};

class MyHashMap {
    unordered_set<int> s;
    Node *head, *tail;
public:
    MyHashMap() {
        head = NULL;
        tail = NULL;
    }
    
    void put(int k, int v) {
        // checking if the value already exists
        if (s.find(k) != s.end()){
            Node *temp = head;
            while (temp != NULL){
                // already existing node found
                if (temp -> key == k){
                    temp -> value = v;
                    break;
                }

                temp = temp -> next;
            }

            return;
        }

        // else if the key doesn't already exists
        s.insert(k);
        Node *newnode = new Node(k, v, NULL);
        // first node
        if (head == NULL && tail == NULL){
            head = newnode;
            tail = newnode;
        }
        // appending at the end
        else {
            tail -> next = newnode;
            tail = tail -> next;
        }
    }
    
    int get(int k) {
        // checking if the key is not present in the hashmap
        if (s.find(k) == s.end()){
            return -1;
        }

        // else the key is present in the map
        Node *temp = head;
        while (temp != NULL){
            // if the node is found
            if (temp -> key == k){
                return temp -> value;
            }

            temp = temp -> next;
        }

        return -1;
    }
    
    void remove(int k) {
        // if this key is not present in the map
        if (s.find(k) == s.end()){
            return;
        }

        // else it is present in the map
        // single node deletion
        if (head == tail && head->key == k){
            delete head;
            head = NULL;
            tail = NULL;
            s.erase(k);
            return;
        }
        // removing at the head
        if (head -> key == k){
            Node *temp = head;
            head = head -> next;
            delete temp;
            s.erase(k);
            return;
        }

        // otherwise
        Node *temp = head;
        while (temp -> next != NULL && temp -> next -> key != k){
            temp = temp -> next;
        }

        // removing at tail
        if (temp -> next == tail){
            tail = temp;
        }

        Node *rem = temp -> next;
        temp -> next = rem -> next;
        delete rem;
        s.erase(k);
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */