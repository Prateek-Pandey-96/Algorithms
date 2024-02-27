// 200. Number of Islands

class Solution {
public:
    void DFS(vector<vector<char>>& grid, int x, int y){
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        grid[newx][newy] = '2';
        for(int i=0; i<4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if (newx < grid.size() and newy < grid[0].size() and grid[newx][newy]=='1'){
                DFS(grid, newx, newy);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        /*
        Plain dfs on a grid
        We can use grid matrix as a visited array to save space
        */
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
};