// 1029. Two City Scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> city1Affinity;
        int n = costs.size();

        for(int i=0; i<n; i++)
            city1Affinity.push_back({costs[i][0]-costs[i][1], i});
        sort(city1Affinity.begin(), city1Affinity.end());

        int min_cost = 0;
        for(int i=0; i<n; i++){
            if(i<n/2)
                min_cost += costs[city1Affinity[i].second][0];
            else
                min_cost += costs[city1Affinity[i].second][1];
        }

        return min_cost;
    }
};