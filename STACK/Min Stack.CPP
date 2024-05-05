// 155. Min Stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    MinStack() {
        while(!s.empty())
            s.pop();
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            s.push(val);
        }else{
            int min_value = min(val, s.top());
            s.push(val);
            s.push(min_value);
        }
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        int min_value = s.top();
        s.pop();
        int top = s.top();
        s.pop();
    }
    
    int top() {
        if(s.empty())
            return -1;
        int min_value = s.top();
        s.pop();
        int top = s.top();
        s.push(min_value);
        return top;
    }
    
    int getMin() {
        if(s.empty())
            return -1;
        return s.top();
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