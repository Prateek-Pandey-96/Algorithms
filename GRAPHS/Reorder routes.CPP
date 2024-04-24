// 1466. Reorder Routes to Make All Paths Lead to the City Zero

class Solution {
public:
    void dfs(int src, int parent, vector<int> adj[], int& required_reversals, set<vector<int>>& edges){

        for(auto child: adj[src]){
            if(child!=parent)
            {
                if(edges.contains({src, child}))
                    required_reversals++;
                dfs(child, src, adj, required_reversals, edges);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        set<vector<int>> edges(connections.begin(), connections.end());
        vector<int> adj[n];
        for(vector<int> connection: connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int required_reversals = 0;
        dfs(0, -1, adj, required_reversals, edges);

        return required_reversals;
    }
};


// 1466. Reorder Routes to Make All Paths Lead to the City Zero -> saving space and decreasing run time

class Solution {
public:
    void dfs(int src, int parent, vector<pair<int, int>> adj[], int& required_reversals){

        for(auto [child, sign]: adj[src]){
            if(child!=parent)
            {
                required_reversals += sign;
                dfs(child, src, adj, required_reversals);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for(vector<int> connection: connections){
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }

        int required_reversals = 0;
        dfs(0, -1, adj, required_reversals);

        return required_reversals;
    }
};