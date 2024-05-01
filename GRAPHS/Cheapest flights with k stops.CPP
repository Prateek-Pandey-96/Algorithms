// 787. Cheapest Flights Within K Stops

#define pp pair<int, pair<int, int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // modified djikstra
        vector<pair<int, int>> adj[n];
        for(vector<int> flight: flights)
            adj[flight[0]].push_back({flight[1], flight[2]});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<pp, vector<pp>, greater<pp>> q;
        // {cost, {city, stops_made}}
        q.push({0, {src, 0}});
        
        while(!q.empty()){
            pp front = q.top();
            q.pop();
            int src = front.second.first, cost = front.first, stops = front.second.second;
            if(stops > k+1 || (stops == k+1 and dst != src))
                continue;
            if(src == dst)
                return cost;
            for(auto [child, wt]: adj[src]){
                if(cost+wt < dist[child]){
                    dist[child] = cost+wt;
                    q.push({dist[child], {child, stops+1}});
                }
            }
        }

        return -1;
    }
};