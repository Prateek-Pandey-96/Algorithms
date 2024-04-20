// 1406. Stone Game III

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+10, 0);
        int sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += stoneValue[i];
            dp[i] = stoneValue[i] + min({dp[i+2], dp[i+3], dp[i+4]});
            if(i+1 < n)
                dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1] + min({dp[i+3], dp[i+4], dp[i+5]}));
            if(i+2 < n)
                dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1] + stoneValue[i+2] + min({dp[i+4], dp[i+5], dp[i+6]}));
        }

        int alice_points = dp[0];
        if(sum-alice_points == alice_points)
            return "Tie";
        return sum - alice_points < alice_points? "Alice": "Bob";
    }
};