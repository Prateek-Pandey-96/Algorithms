// 1020. Number of Enclaves

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y){
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        grid[x][y] = 0;
        for(int i=0; i<4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if(newx >= 0 and newy >= 0 and newx < grid.size() and newy < grid[0].size() and grid[newx][newy])
                dfs(grid, newx, newy);
        } 
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i=0; i<m; i++)
        {
            if(grid[i][0])
                dfs(grid, i, 0);
            if(grid[i][n-1])
                dfs(grid, i, n-1);
        }
        for(int j=0; j<n; j++)
        {
            if(grid[0][j])
                dfs(grid, 0, j);
            if(grid[m-1][j])
                dfs(grid, m-1, j);
        }

        int count = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j])
                    count++;
        return count;
    }
};