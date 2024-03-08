// 463. Island Perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int perimeter = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    if(j==n-1 || (j<n and grid[i][j+1]==0)) perimeter++;
                    if(i==m-1 || (i<m and grid[i+1][j]==0)) perimeter++;
                    if(j==0 || (j>0 and grid[i][j-1]==0)) perimeter++;
                    if(i==0 || (i>0 and grid[i-1][j]==0)) perimeter++;
                }
            }
        }
        return perimeter;
    }
};