// 1857. Largest Color Value in a Directed Graph

class Solution {
public:
    bool IsCyclic(int src, vector<int>& visited, vector<int> adj[]){
        visited[src] = 1;
        visited[src] = 2;

        for(auto child: adj[src]){
            if(!visited[child]){
                bool check_further = IsCyclic(child, visited, adj);
                if(check_further)
                    return true;
            }else if(visited[child]==2)
                return true;
        }

        visited[src] = 1;
        return false;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> adj[n];
        vector<int> visited(n, 0);
        vector<int> indegree(n, 0);
        
        // construct graph
        for(vector<int> edge: edges)
            adj[edge[0]].push_back(edge[1]), indegree[edge[1]]++;
        
        // check for a cycle
        for(int i=0; i<n; i++){
            if(!visited[i])
            {
                bool is_cyclic = IsCyclic(i, visited, adj);
                if(is_cyclic)
                    return -1;
            }
        }


        // modified kahn's algorithm
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i])
            {
                q.push(i);
                dp[i][colors[i]-'a']++;
            }
        }

        int largest_color_value = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int src = q.front();
                q.pop();
                for(int i=0; i<26; i++)
                    largest_color_value = max(largest_color_value, dp[src][i]);
                for(auto child: adj[src]){
                    indegree[child]--;
                    for(int i=0; i<26; i++){
                        dp[child][i] = max(dp[child][i], dp[src][i] + (i==colors[child]-'a'));
                    }
                    if(!indegree[child]){
                        q.push(child);
                    }
                }
            }
        }
        return largest_color_value;
    }
};