// 834. Sum of Distances in Tree

class Solution {
public:
    int N, d;
    int postorder_dfs(int src, int par, vector<int> adj[], vector<int>& subtree, int k){
        d += k;
        int nodes = 1;
        for(auto child: adj[src]){
            if(child == par)
                continue;
            nodes += postorder_dfs(child, src, adj, subtree, k+1);
        }
        subtree[src] = nodes;
        return nodes;
    }
    
    void inorder_dfs(int src, int par, vector<int> adj[], vector<int>& subtree, vector<int>& dist){
        if(par != -1)
            dist[src] = dist[par] - subtree[src] + N - subtree[src];
        for(auto child: adj[src]){
            if(child==par)
                continue;
            inorder_dfs(child, src, adj, subtree, dist);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n, d = 0;
        vector<int> adj[n];
        for(vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> subtree(n, 0);
        
        // step-1 get subtree size
        postorder_dfs(0, -1, adj, subtree, 0);

        // step-2 go from root to bottom
        vector<int> dist(n, 0);
        dist[0] += d;
        inorder_dfs(0, -1, adj, subtree, dist);
        
        // step-3 return ans
        return dist;
    }
};