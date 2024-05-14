// 1219. Path with Maximum Gold
class Solution {
public:
    int m, n;
    int dx[4]={1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int dfs(vector<vector<int>>& grid, int x, int y){
        int gold = grid[x][y];
        grid[x][y] = 0; 

        int additional_gold = 0;
        for(int i=0; i<4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if(newx >= 0 and newx < m and newy >= 0 and newy < n and grid[newx][newy])
                additional_gold = max(additional_gold, dfs(grid, newx, newy));
        }

        grid[x][y] = gold;
        return gold + additional_gold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int gold = 0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j])
                    gold = max(gold, dfs(grid, i, j));
        
        return gold;
    }
};