// 785. Is Graph Bipartite?

class Solution {
public:
    bool IsInvalid(int src, vector<int> adj[], vector<int>& color, int curr_color){
        color[src] = curr_color;

        for(auto child: adj[src]){
            if(color[child] == -1){
                bool check = IsInvalid(child, adj, color, !curr_color);
                if(check)
                    return true;
            }else if(color[child] == curr_color)
                return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> color(n, -1);

        for(int i=0; i<n; i++)
            for(int j=0; j<graph[i].size(); j++)
                adj[i].push_back(graph[i][j]);
            
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                bool check = IsInvalid(i, adj, color, 0);
                if(check)
                    return false; 
            }
        }
        return true;
    }
};