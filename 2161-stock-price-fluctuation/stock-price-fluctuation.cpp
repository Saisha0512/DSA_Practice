class StockPrice {
    int max_time;
    multiset<int> prices;
    unordered_map<int, int> records;

public:
    StockPrice() {
        max_time = 0;
    }
    
    void update(int timestamp, int price) {
        // if the timestamp is already present
        if (records.count(timestamp)){
            // removing this old price from the multiset
            auto it = prices.find(records[timestamp]);
            prices.erase(it);
        }

        max_time = max(max_time, timestamp);
        records[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return records[max_time];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
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