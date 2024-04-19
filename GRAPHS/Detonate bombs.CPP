// 2101. Detonate the Maximum Bombs
class Solution {
public:
    int dfs(int src, vector<bool>& visited, vector<int> adj[]){
        visited[src] = true;
        int bombs = 1;
        for(auto dest: adj[src]){
            if(!visited[dest])
                bombs += dfs(dest, visited, adj);

        }
        return bombs;
    }
    // Return the largest connected component in a directed graph
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j=i+1; j<n; j++){
                int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long dist_center_squared = (long)(x1-x2)*(x1-x2)+(long)(y1-y2)*(y1-y2);
                if(dist_center_squared <= (long)r1*r1)
                    adj[i].push_back(j);
                if(dist_center_squared <= (long)r2*r2)
                    adj[j].push_back(i);
            }  
        }

        
        int max_bombs = 0;

        for(int i=0; i<n; i++){
            vector<bool> visited(n, false);
            max_bombs = max(max_bombs, dfs(i, visited, adj));
        }

        return max_bombs;
    }
};