// 1140. Stone Game II

class Solution {
public:
    int DFS(vector<int>& piles, int idx, int M, vector<vector<int>>& dp){
        int n = piles.size();
        if(idx >= n)
            return 0;
        if(dp[idx][M]!=-1)
            return dp[idx][M];
        // alice takses 1 or 2*M coins
        int max_points = 0, points = 0, x = 0;
        for(int i=idx; i<=(idx+2*M-1) and i<n; i++){
            points += piles[i];
            x += 1;
            int newM = max(M, x);
            int minAdditionalPoints = INT_MAX;
            int y = 0;
            for(int j=i+1; j<=i+1+2*newM-1 and j<n; j++){
                y += 1;
                minAdditionalPoints = min(minAdditionalPoints, DFS(piles, j+1, max(newM, y), dp));
            }
            if(minAdditionalPoints == INT_MAX)
                minAdditionalPoints = 0;
            max_points = max(max_points, points + minAdditionalPoints);
        }
        return dp[idx][M] = max_points;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size()+1, vector<int>(201 , -1));
        return DFS(piles, 0, 1, dp);
    }
};