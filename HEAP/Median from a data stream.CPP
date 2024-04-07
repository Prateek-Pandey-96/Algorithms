// 295. Find Median from Data Stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;
    MedianFinder() {
        while(!firstHalf.empty()) firstHalf.pop();
        while(!secondHalf.empty()) secondHalf.pop();
    }
    
    void addNum(int num) {
        if(firstHalf.empty() || num < firstHalf.top())
            firstHalf.push(num);
        else
            secondHalf.push(num);
        
        if(firstHalf.size() > secondHalf.size()+1){
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }else if(secondHalf.size() > firstHalf.size()+1){
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
    }
    
    double findMedian() {
        int m = firstHalf.size(), n = secondHalf.size();
        if(m==n)
            return (double)(firstHalf.top() + secondHalf.top())/2.0;
        else if(m==n+1)
            return (double)firstHalf.top();
        else
            return  (double)secondHalf.top();
        return 0.0;
    }
};
