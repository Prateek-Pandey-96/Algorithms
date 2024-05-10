// 786. K-th Smallest Prime Fraction

#define maxHeap priority_queue<pair<double, pair<int, int>>>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        maxHeap pq;
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                pq.push({1.0*arr[i]/arr[j], {arr[i], arr[j]}});
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};