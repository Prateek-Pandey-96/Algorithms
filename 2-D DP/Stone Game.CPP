//877. Stone Game

class Solution {
public:
    int Helper(vector<int>& piles, int start, int end, vector<vector<int>>& dp){
        if(start > end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        // pick from start and choose optimally
        int possibility1 = piles[start] + max(Helper(piles, start+1, end-1, dp), Helper(piles, start+2, end, dp));
        // pick from end choose optimally
        int possibility2 = piles[end] + max(Helper(piles, start, end-1, dp), Helper(piles, start+1, end-1, dp));
        return dp[start][end] = max(possibility1, possibility2);
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), total_points = 0;
        for(int pile: piles) 
            total_points += pile;
        vector<vector<int>> dp(501, vector<int>(501, -1));
        int alice_points = Helper(piles, 0, n-1, dp);
        return alice_points > total_points - alice_points;
    }
};