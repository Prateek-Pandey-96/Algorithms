// 1866. Number of Ways to Rearrange Sticks With K Sticks Visible

class Solution {
public:
    // int mod = 1e9+7;
    // long dfs(int n, int k, vector<vector<long>>& dp){
    //     if((n==0 and k!=0) || (k==0 and n!=0))
    //         return 0;
    //     if(n==k)
    //         return 1;
    //     if(k>n)
    //         return 0;
    //     if(dp[n][k]!=-1)
    //         return dp[n][k];
    //     // if(n>k) proceed
    //     return dp[n][k] = (dfs(n-1, k-1, dp) + ((n-1)%mod * dfs(n-1, k, dp)%mod)%mod)%mod;
    // }
    int rearrangeSticks(int n, int k) {
        vector<vector<long>> dp(n+1, vector<long>(k+1, 0));
        int mod = 1e9+7;
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                if(i==j)
                    dp[i][j] = 1;
                else if(i>j)
                    dp[i][j] = (dp[i-1][j-1] + ((i-1)%mod * dp[i-1][j]%mod)%mod)%mod;
            }
        }
        return (int)dp[n][k];
    }
};