// 1293. Shortest Path in a Grid with Obstacles Elimination

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        bool visited[m+1][n+1][k+1];
        memset(visited, false, sizeof visited);
        queue<pair<int, pair<int, int>>> q;

        q.push({k, {0, 0}});
        visited[0][0][k] = true;
        int level = -1, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

        while(!q.empty()){
            int size = q.size();
            level++;
            while(size--)
            {
                pair<int, pair<int, int>> front = q.front();
                q.pop();
                int obstaclesLeft = front.first, x = front.second.first, y = front.second.second;
                if(x == m-1 and y == n-1)
                    return level;
                
                for(int i=0; i<4; i++){
                    int newx = x+dx[i], newy = y+dy[i];
                    if(newx >= 0 and newx < m and newy >= 0 and newy < n and !visited[newx][newy][obstaclesLeft]){
                        if(grid[newx][newy]==0){
                            q.push({obstaclesLeft, {newx, newy}});
                            visited[newx][newy][obstaclesLeft] = true;
                        }else{
                            if(obstaclesLeft > 0){
                                q.push({obstaclesLeft-1, {newx, newy}});
                                visited[newx][newy][obstaclesLeft-1] = true;
                            }
                        }
                    }
                }
            } 
        }

        return -1;
    }
};