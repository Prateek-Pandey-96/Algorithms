// 895. Maximum Frequency Stack

class FreqStack {
public:
    int max_f;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> stackmap;
    FreqStack() {
        freq.clear();
        stackmap.clear();
        max_f = -1;
    }
    
    void push(int val) {
        freq[val]++;
        stackmap[freq[val]].push(val);
        max_f = max(max_f, freq[val]);
    }
    
    int pop() {
        int val = stackmap[max_f].top();
        freq[val]--;
        if(!freq[val])
            freq.erase(val);
        stackmap[max_f].pop();
        if(!stackmap[max_f].size()){
            stackmap.erase(max_f);
            max_f--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */