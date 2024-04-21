// 221. Maximal Square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int max_side_length = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0){
                    if(matrix[i][j]=='1')
                    {
                        dp[i][j] = 1;
                        max_side_length = max(max_side_length, dp[i][j]);
                    }
                }
                else if(matrix[i][j]!='0'){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    max_side_length = max(max_side_length, dp[i][j]);
                }
            }
        }
        return max_side_length * max_side_length;
    }
};