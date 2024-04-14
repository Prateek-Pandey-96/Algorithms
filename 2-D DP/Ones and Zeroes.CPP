// 474. Ones and Zeroes

class Solution {
public:
    unordered_map<int, int> zeroes, ones;
    int idx;
    int findMaxForm(vector<string>& strs, int m, int n) {
        zeroes.clear(), ones.clear();
        idx = 0;
        for(string str: strs){
            int zero = 0, one = 0;
            for(char ch: str){
                if(ch=='1')
                    one++;
                else
                    zero++;
            }
            zeroes[idx] = zero, ones[idx] = one;
            idx++;
        }
        int size = idx;
        int dp[size+1][m+1][n+1];
        memset(dp, 0, sizeof dp);

        for(int i=1; i<=size; i++){
            int zero = zeroes[i-1], one = ones[i-1];
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n; k++){
                    if(zero <= j and one <= k)
                        dp[i][j][k] = max(dp[i-1][j][k], 1 + dp[i-1][j-zero][k-one]);
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }

        return dp[size][m][n];
    }
};