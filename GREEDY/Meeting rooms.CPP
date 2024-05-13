// Interview Bit

int Solution::solve(vector<vector<int> > &meetings) {
    // heap will be required as any of previous rooms can become empty
    int n = meetings.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    sort(meetings.begin(), meetings.end());
    
    for(int i=0; i<n; i++){
       if(minHeap.empty()){
           minHeap.push(meetings[i][1]);
       }else{
           int top = minHeap.top();
           if(top <= meetings[i][0]){
               minHeap.pop();
               minHeap.push(meetings[i][1]);
           }else{
               minHeap.push(meetings[i][1]);
           }
       }
    }
    
    return minHeap.size();
}
