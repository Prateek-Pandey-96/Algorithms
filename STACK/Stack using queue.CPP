class MyStack {
public:
    /* Initialize your data structure here. */
    /* All calls are valid. */
    queue<int> q1, q2;
    MyStack() {
        q1.empty();
        q2.empty();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans;
        if(q1.empty()){
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            ans = q2.front();
            q2.pop();
        }else{
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            ans = q1.front();
            q1.pop();
        }
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        int ans;
        if(q1.empty()){
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            ans = q2.front();
            q1.push(q2.front());
            q2.pop();
        }else{
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            ans = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return !q1.size() and !q2.size();
    }
};
