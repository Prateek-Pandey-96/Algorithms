// 1462. Course Schedule IV

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(numCourses);
        vector<int> adj[numCourses];
        for(vector<int> prerequisite: prerequisites)
        {
            adj[prerequisite[0]].push_back(prerequisite[1]);
            indegree[prerequisite[1]]++;
        }
        
        unordered_map<int, unordered_set<int>> hashmap;

        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto child: adj[front]){
                indegree[child]--;

                hashmap[child].insert(front);
                for(auto u: hashmap[front])
                    hashmap[child].insert(u);

                if(indegree[child]==0)
                    q.push(child);
            }
        }
        
        vector<bool> result;
        for(vector<int> query: queries){
            if(hashmap[query[1]].contains(query[0]))
                result.push_back(true);
            else
                result.push_back(false);
        }


        return result;
    }
};