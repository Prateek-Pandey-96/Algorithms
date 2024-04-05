// 1834. Single-Threaded CPU

class Solution {
public:
    struct Task{
        int startTime;
        int timeRequired;
        int idx;
        Task(int startTime, int timeRequired, int idx){
            this->startTime = startTime;
            this->timeRequired = timeRequired;
            this->idx = idx;
        }
    };

    struct CompareTasks {
        bool operator()(Task a, Task b) {
            if(a.timeRequired == b.timeRequired)
                return a.idx > b.idx;
            return a.timeRequired > b.timeRequired;
        }
    };

    static bool CompareInit(Task a, Task b){
        if(a.startTime == b.startTime)
            return a.timeRequired < b.timeRequired;
        return a.startTime < b.startTime;
    }
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<Task> Tasks;
        int n = tasks.size();
        for(int i=0; i<n; i++)
            Tasks.push_back(Task(tasks[i][0], tasks[i][1], i));
    
        sort(Tasks.begin(), Tasks.end(), CompareInit);
        vector<int> result;
        
        priority_queue<Task, vector<Task>, CompareTasks> minHeap;
        int idx = 0;  
        while(idx<n){
            int time = Tasks[idx].startTime; 
            while(idx < n and Tasks[idx].startTime == time)
                minHeap.push(Tasks[idx++]);
            while(!minHeap.empty())
            {
                Task curr = minHeap.top();
                minHeap.pop();
                result.push_back(curr.idx);
                long timeLimit = (long)curr.timeRequired + (long)max(time, curr.startTime);
                while(idx < n and Tasks[idx].startTime <= timeLimit)
                    minHeap.push(Tasks[idx++]);
                time = timeLimit;
            }
        }

        return result;
    }
};