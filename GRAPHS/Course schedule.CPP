// 207. Course Schedule

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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            There shouldn't be any cycle in the directed graph
        */
        vector<int> adj[numCourses];
        vector<int> visited(numCourses, 0);
        
        for(vector<int> prerequisite: prerequisites)
            adj[prerequisite[1]].push_back(prerequisite[0]);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool is_cyclic = isCyclic(i, adj, visited);
                if(is_cyclic)
                    return false;
            }
        }
        return true;
    }
};