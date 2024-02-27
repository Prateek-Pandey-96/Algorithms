// 695. Max Area of Island

class Solution {
public:
    int DFS(vector<vector<int>>& grid, int x, int y){
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

        int curr_size = 1;
        /* Mark the cell as visited as soon as you enter the recurion for the cell */
        grid[x][y] = 2;
        
        for(int i=0; i<4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if (newx < grid.size() and newy < grid[0].size() and grid[newx][newy]==1){
                curr_size += DFS(grid, newx, newy);
            }
        }
        
        return curr_size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    max_area = max(max_area, DFS(grid, i, j));
                }
            }
        }
        return max_area;
    }
};