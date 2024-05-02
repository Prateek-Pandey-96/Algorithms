// 2492. Minimum Score of a Path Between Two Cities

class Solution {
public:
    void DFS(int src, vector<pair<int, int>> adj[], vector<bool>& visited, int& min_edge){
        visited[src] = true;

        for(auto [child, dist]: adj[src]){
            min_edge = min(min_edge, dist);
            if(!visited[child])
                DFS(child, adj, visited, min_edge);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n+1];
        for(vector<int> road: roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // find the minimum edge in the connected component contating 1 and n
        vector<bool> visited(n+1, false);
        int min_edge = INT_MAX;
        DFS(1, adj, visited, min_edge);

        return min_edge;
    }
};