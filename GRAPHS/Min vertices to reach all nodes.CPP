// 1557. Minimum Number of Vertices to Reach All Nodes

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(vector<int> edge: edges){
            indegree[edge[1]]++;
        }   
        vector<int> result;
        for(int i=0; i<n; i++)
            if(!indegree[i])
                result.push_back(i);
        return result;
    }
};