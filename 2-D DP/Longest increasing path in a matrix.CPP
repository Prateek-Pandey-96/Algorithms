// 329. Longest Increasing Path in a Matrix

class Solution {
public:
    int m, n;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int dp[201][201];
    int DFS(vector<vector<int>>& matrix, int x, int y){
        if(dp[x][y] != -1)
            return dp[x][y];
        
        int temp = matrix[x][y];
        matrix[x][y] = -1;
        
        int max_len = 1;
        for(int i=0; i<4; i++)
        {
            int newx = x+dx[i], newy = y+dy[i];
            if(newx>=0 and newx<m and newy>=0 and newy<n and matrix[newx][newy]>temp){
                max_len = max(max_len, 1 + DFS(matrix, newx, newy));
            }
        }

        matrix[x][y] = temp;
        return dp[x][y] = max_len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        memset(dp, -1, sizeof dp);
        int max_length = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                max_length = max(max_length, DFS(matrix, i, j));
            }
        }
        return max_length;
    }
};