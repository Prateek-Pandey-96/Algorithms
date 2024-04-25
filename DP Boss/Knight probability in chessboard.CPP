// 688. Knight Probability in Chessboard

class Solution {
public:
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1}, dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    double dp[101][26][26];
    double Helper(int n, int k, int row, int col){
        if(k==0)
            return 1.0;
        if(dp[k][row][col]!=0)
            return dp[k][row][col];
        double probability = 0.0;
        for(int i=0; i<8; i++){
            int newrow = row + dx[i], newcol = col + dy[i];
            if(newrow < n and newcol < n and newrow >= 0 and newcol >= 0){
                probability += (0.125) * Helper(n, k-1, newrow, newcol);
            }
        }

        return dp[k][row][col]=probability;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, 0, sizeof dp);
        return Helper(n, k, row, column);
    }
};