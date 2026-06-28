class StockPrice {
    map<int, int> records; // {timestamp, price}
    map<int, int> freq; // {price, freq}

public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        // if the timestamp already exists
        if (records.count(timestamp)){
            int old_price = records[timestamp];
            freq[old_price] --;

            if (freq[old_price] == 0){
                freq.erase(old_price);
            }
        }

        records[timestamp] = price;
        freq[price] ++;
    }
    
    int current() {
        auto it = records.rbegin();
        return it -> second;
    }
    
    int maximum() {
        auto it = freq.rbegin();
        return it -> first;
    }
    
    int minimum() {
        auto it = freq.begin();
        return it -> first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */