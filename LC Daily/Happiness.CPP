// 3075. Maximize Happiness of Selected Children

#define minHeap priority_queue<int, vector<int>, greater<int>>
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        minHeap pq;
        int n = happiness.size();
        for(int i=0; i<n; i++){
            pq.push(happiness[i]);
            if(pq.size()>k)
                pq.pop();
        }
        
        // we now have k max elements
        vector<int> temp;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            temp.push_back(top);
        }

        // calculate max happiness
        long long result = 0;
        int ctr = 0;
        for(int i=temp.size()-1; i>=0; i--)
        {
            if((long long)temp[i]-(long long)ctr > 0)
                result += (long long)temp[i]-(long long)ctr;
            ctr += 1;
        }

        return result;
    }
};