// 934. Shortest Bridge

class Solution {
public:
    int m, n;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q){
        grid[x][y] = 2;
        q.push({x, y});
        
        for(int k=0; k<4; k++){
            int newx = x + dx[k], newy = y + dy[k];
            if(newx >= 0 and newy >= 0 and newx < m and newy < n and grid[newx][newy]==1){
                dfs(grid, newx, newy, q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        /*
            First do a dfs and put whole island in a queue
        */
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++)
        {
            bool flag = false;
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                {
                    dfs(grid, i, j, q);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        /*
            Now do a bfs to find other island
        */
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    int newx = x + dx[k], newy = y + dy[k];
                    if(newx >= 0 and newy >= 0 and newx < m and newy < n and grid[newx][newy]==0){
                        q.push({newx, newy});
                        grid[newx][newy]=2;
                    }else if (newx >= 0 and newy >= 0 and newx < m and newy < n and grid[newx][newy]==1){
                        return level;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};