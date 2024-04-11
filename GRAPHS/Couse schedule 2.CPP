// 210. Course Schedule II
class Solution {
public:
    bool isCyclic(int u, vector<int> adj[], vector<int>& visited){
        visited[u] = 1;
        visited[u] = 2;

        for(auto v: adj[u]){
            if(visited[v]==0){
                bool is_cyclic = isCyclic(v, adj, visited);
                if(is_cyclic)
                    return true;
            }else if(visited[v]!=0 and visited[v] == 2)
                return true;
        }

        visited[u] = 1;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> visited(numCourses, 0);
        vector<int> indegree(numCourses, 0);

        for(vector<int> prerequisite: prerequisites)
        {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool is_cyclic = isCyclic(i, adj, visited);
                if(is_cyclic)
                    return {};
            }
        }
        // If no cycle is present we will do topological sort
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(!indegree[i])
                q.push(i);
        
        vector<int> topo_sorted_sequence;
        while(!q.empty()){
            int from_vertex = q.front();
            q.pop();
            topo_sorted_sequence.push_back(from_vertex);

            for(auto to_vertex: adj[from_vertex]){
                indegree[to_vertex]--;
                if(!indegree[to_vertex]){
                    q.push(to_vertex);
                }
            }
        }

        return topo_sorted_sequence;
    }
};