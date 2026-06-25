class RLEIterator {
    int pt, size;
    vector<int> encoding;
public:
    RLEIterator(vector<int>& encoding) {
        this -> encoding = encoding;
        pt = 1;
        size = encoding.size();
    }
    
    int next(int n) {
        if (n == 0){
            return -1;
        }

        int last_el = -1;
        while (n && pt < size){
            if (encoding[pt - 1] <= n){
                n -= encoding[pt - 1];
                last_el = encoding[pt];
                encoding[pt - 1] -= encoding[pt - 1];
            }
            else {
                encoding[pt - 1] -= n;
                n -= n;
                last_el = encoding[pt];
            }

            if (encoding[pt - 1] == 0){
                pt += 2;
            }
        }

        if (n != 0){
            return -1;
        }

        return last_el;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */