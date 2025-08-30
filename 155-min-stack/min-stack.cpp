class MinStack {
public:
    stack<int> s1, s2;
    MinStack() {
    }
    
    void push(int val) {
        s1.push(val);
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        int res = INT_MAX;
        while (!s1.empty()){
            int el = s1.top();
            s1.pop();
            s2.push(el);
            if (el < res){
                res = el;
            }
        }
        while (!s2.empty()){
            int el = s2.top();
            s2.pop();
            s1.push(el);
        }
        return res;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */