// 115. Distinct Subsequences

class Solution {
public:
    // int dp[1001][1001];
    // int RecursiveHelper(string s, string t, int idx_s, int idx_t){
    //     if(idx_t==t.length())
    //         return 1;
    //     if(idx_s==s.length())
    //         return 0;
    //     if(dp[idx_s][idx_t] != -1)
    //         return dp[idx_s][idx_t];
    //     if(s[idx_s]!=t[idx_t])
    //         return dp[idx_s][idx_t] = RecursiveHelper(s, t, idx_s+1, idx_t);
    //     return dp[idx_s][idx_t] = RecursiveHelper(s, t, idx_s+1, idx_t+1) + RecursiveHelper(s, t, idx_s+1, idx_t);
    // }
    int numDistinct(string s, string t) {
        // memset(dp, -1, sizeof dp);
        // return RecursiveHelper(s, t, 0, 0);
        int n = s.length(), m = t.length();
        vector<vector<unsigned long>> dp(m+1, vector<unsigned long>(n+1, 0));
        for(int i=0; i<=n; i++)
            dp[0][i]=1;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[j-1]==t[i-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return (int)dp[m][n];
    }
};