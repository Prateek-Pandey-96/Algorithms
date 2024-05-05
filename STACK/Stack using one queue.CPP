class MyStack {
public:
    queue<int> q;
    MyStack() {
        while(!q.empty())
            q.pop();
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
