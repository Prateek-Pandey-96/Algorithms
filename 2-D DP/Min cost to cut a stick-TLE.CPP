// 1547. Minimum Cost to Cut a Stick

class Solution {
public:
    int DFS(int n, int low, int high, vector<int>& cuts, vector<vector<int>>& dp){
        if(low >= high)
            return 0;
        if(dp[low][high]!=-1)
            return dp[low][high]; 
        int min_cost = INT_MAX;
        for(int i=0; i<cuts.size(); i++){
            if(cuts[i]<=low || cuts[i]>=high)
                continue;
            min_cost = min(min_cost, high-low + DFS(n, low, cuts[i], cuts, dp) + DFS(n, cuts[i], high, cuts, dp));
        }
        return dp[low][high] = min_cost!=INT_MAX? min_cost: 0;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return DFS(n, 0, n, cuts, dp);
    }
};