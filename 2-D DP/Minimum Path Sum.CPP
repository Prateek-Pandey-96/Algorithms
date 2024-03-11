// 64. Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // at each cell we can either come from cell[i-1][j] or cell[i][j-1] choose the min one
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 and j==0)
                    continue;
                else if(i==0)
                    grid[i][j] += grid[i][j-1];
                else if(j==0)
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};