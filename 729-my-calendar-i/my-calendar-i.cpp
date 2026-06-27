class MyCalendar {
    vector<pair<int, int>> calendar;
public:
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        for (auto &[start, end] : calendar){
            if (start < e && s < end){
                return false;
            }
        }

        calendar.push_back({s, e});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */