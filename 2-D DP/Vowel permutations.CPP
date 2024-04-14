// 1220. Count Vowels Permutation
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(5, vector<int>(n, 0));
        int mod = 1e9 + 7;
        for(int i=0; i<5; i++)
            dp[i][0] = 1;
        /*
         a
         e
         i
         o
         u
        */
        for(int j=1; j<n; j++){
            dp[0][j] = ((dp[1][j-1] + dp[2][j-1])%mod + dp[4][j-1])%mod;
            dp[1][j] = (dp[0][j-1] + dp[2][j-1])%mod;
            dp[2][j] = (dp[1][j-1] + dp[3][j-1])%mod;
            dp[3][j] = dp[2][j-1];
            dp[4][j] = (dp[2][j-1] + dp[3][j-1])%mod;
        }
        int result = 0;
        for(int i=0; i<5; i++)
            result = (result + dp[i][n-1])%mod;
        return result;
    }
};