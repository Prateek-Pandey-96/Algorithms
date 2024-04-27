// 802. Find Eventual Safe States

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // put all the nodes with 0 outdegree in a queue
        // find a way to know about all the edges that reach node
        int n = graph.size();
        vector<int> adj[n];
        vector<int> outdegree(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);
                outdegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++)
            if(!outdegree[i])
                q.push(i);
            
        vector<int> result;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            result.push_back(front);

            for(auto child: adj[front]){
                outdegree[child]--;
                if(!outdegree[child])
                    q.push(child);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};