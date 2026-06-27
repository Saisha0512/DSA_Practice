class DetectSquares {
    unordered_map<string, int> m;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        string key = to_string(x) + "_" + to_string(y);
        m[key] ++;
    }
    
    int count(vector<int> point) {
        int cnt = 0;
        int x = point[0], y = point[1];

        for (auto &p : m){
            string key = p.first;
            int pos = key.find('_');

            int i = stoi(key.substr(0, pos)), j = stoi(key.substr(pos + 1));

            // ignore
            if (i == x || j == y || abs(x - i) != abs(y - j)){
                continue;
            }

            string key1 = to_string(x) + "_" + to_string(j); // {x, j}
            string key2 = to_string(i) + "_" + to_string(y); // {i, y}
            if (m.count(key1) && m.count(key2)){
                cnt += (p.second * m[key1] * m[key2]);
            }
        }

        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */