//994. Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // looks like a multisource bfs
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int fresh = 0, empty = 0, rotten = 0;
        
        // put all the rotten oranges into q
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j]==2)
                    grid[i][j]=0, q.push({i, j});
                else if(grid[i][j]==1)
                    fresh++;
                else 
                    empty++;
        rotten = q.size();

        // no fresh orange so time required will be zero
        if(fresh==0)
            return 0;
        
        // direction vectors to move to adjacent cells
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        // bfs to count min
        int levels = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front = q.front();
                q.pop();

                for(int dir = 0; dir < 4; dir++){
                    int newx = front.first + dx[dir];
                    int newy = front.second + dy[dir];

                    if(newx >= 0 and newy >= 0 and newx < m and newy < n and grid[newx][newy]==1)
                    {
                        grid[newx][newy]=0;
                        rotten +=1;
                        q.push({newx, newy});
                    }
                }
            }
            levels++;
        }
        
        // minutes == levels - 1 == gaps
        return m*n - empty - rotten == 0? levels - 1: -1;
    }
};