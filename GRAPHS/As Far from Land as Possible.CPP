// 1162. As Far from Land as Possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // seems like multisource BFS
        queue<tuple<int, int, int>> q;
        int n = grid.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j])
                    q.push({i, j, 0});

        if(q.size() == 0 || q.size() == n*n)
            return -1;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1}; 
        int maxDist = 0;
        
        while(!q.empty()){
            auto [x, y, dist] = q.front();
            q.pop();

            maxDist = max(maxDist, dist);
            
            for(int i=0; i<4; i++)
            {
                int newx = x + dx[i], newy = y + dy[i];
                if(newx >= 0 and newx < n and newy >= 0 and newy < n and !grid[newx][newy]){
                    // mark visited
                    grid[newx][newy] = 1;
                    q.push({newx, newy, dist + abs(newx-x)+abs(newy-y)});
                }
            }
        }

        return maxDist; 
    }
};