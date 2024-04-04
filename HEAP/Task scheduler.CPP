// 621. Task Scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> freq;
        int size = tasks.size();
        if(size==1)
            return 1;
        for(char task: tasks)
            freq[task-'A']++;
        
        priority_queue<pair<int, int>> maxHeap;
        for(auto [key, val]: freq)
            maxHeap.push({val, key});
        int maxf = maxHeap.top().first;
        maxHeap.pop();

        int idle_time = (maxf-1)*n;
        while(!maxHeap.empty()){
            auto [f, idx] = maxHeap.top();
            maxHeap.pop();

            idle_time -= min(f, maxf-1);
        }
        if(idle_time<0)
            idle_time = 0;
        return idle_time + size;
    }
};