class LRUCache {
    list<int> l;
    unordered_map<int, pair<list<int> :: iterator, int>> mp;
    int n;
public:
    LRUCache(int capacity) {
        this -> n = capacity;
    }

    void makeRecentlyUsed(int key){
        auto it = mp[key].first;
        l.erase(it);
        l.push_front(key);
        mp[key].first = l.begin();
    }
    
    int get(int key) {
        if (mp.count(key)){
            makeRecentlyUsed(key);
            return mp[key].second;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key)){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else {
            if (mp.size() == n){
                int k = l.back();
                l.pop_back();

                mp.erase(k);
            }

            l.push_front(key);
            mp[key] = {l.begin(), value};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */