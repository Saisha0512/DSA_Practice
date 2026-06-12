class MinStack {
    stack<int> s, mins;
    // manintaining 2 stacks simultaneously - original stack & stack to track the minimum element with every new element that comes
public:
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);

        // pushing the minimum value into the min-stack
        if (!mins.empty()){ // non - empty stack
            mins.push(min(value, mins.top()));
        }
        else { // empty stack
            mins.push(value); // first element
        }
    }
    
    void pop() {
        // popping both minimum & current stack simultaneously
        mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */