// 743. Network Delay Time

class Solution {
public:
    /* Dijkstra's Algorithm */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> dist(n+1, INT_MAX);
        
        vector<pair<int, int>> adj[n+1];
        for(vector<int> time: times)
            adj[time[0]].push_back({time[1], time[2]});
        
        minHeap.push({0, k});
        dist[k] = 0;

        while(!minHeap.empty()){
            auto [wt, src] = minHeap.top();
            minHeap.pop();

            for(auto [child, ch_wt]: adj[src]){
                if(wt + ch_wt < dist[child]){
                    dist[child] = wt+ch_wt;
                    minHeap.push({dist[child], child});
                }
            }
        }

        int ans = -1;
        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};