// 2477. Minimum Fuel Cost to Report to the Capital

class Solution {
public:
    long long dfs(int src, int parent, vector<int> adj[], long long seats, long long& fuel){
        long long people = 1;
        for(auto child: adj[src])
            if(child!=parent)
                people += dfs(child, src, adj, seats, fuel);  
            
        if(src != 0)
            fuel += people/seats + ((people%seats)?1:0);

        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int> adj[n];
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        long long fuel = 0;
        long long people = dfs(0, -1, adj, (long long)seats, fuel);
        return fuel;
    }
};