// 2359. Find Closest Node to Given Two Nodes

class Solution {
public:
    void dfs(int src, vector<int>& dist, int curr, vector<int> adj[]){
        dist[src] = curr;

        for(auto child: adj[src]){
            if(dist[child]==INT_MAX)
                dfs(child, dist, curr+1, adj);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // if we perform two dfs store the distances and then take min of both the distances
        int e = edges.size();
        vector<int> adj[e];

        for(int i=0; i<e; i++)
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        vector<int> dist1(e, INT_MAX), dist2(e, INT_MAX);

        dfs(node1, dist1, 0, adj);
        dfs(node2, dist2, 0, adj);

        int temp = INT_MAX;
        int node = -1;
        for(int i=0; i<e; i++){
            if(max(dist1[i], dist2[i]) < temp){
                temp = max(dist1[i], dist2[i]);
                node = i;
            }
        }

        return node;
    }
};