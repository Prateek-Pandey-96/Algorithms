// 1547. Minimum Cost to Cut a Stick

class Solution {
public:
    int DFS(int start, int n, int low, int high, vector<int>& cuts, vector<vector<int>>& dp){
        if(low > high)
            return 0;
        if(dp[low][high]!=-1)
            return dp[low][high]; 
        
        int min_cost = INT_MAX;
        for(int idx=low; idx<=high; idx++){
            min_cost = min(min_cost, n-start + DFS(start, cuts[idx], low, idx-1, cuts, dp) + DFS(cuts[idx], n, idx+1, high, cuts, dp));
        }
        
        return dp[low][high] = min_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        sort(cuts.begin(), cuts.end());
        return DFS(0, n, 0, cuts.size()-1, cuts, dp);
    }
};