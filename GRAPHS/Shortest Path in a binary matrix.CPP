// 1091. Shortest Path in Binary Matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[n-1][n-1] || grid[0][0])
            return -1;
        
        int level = 0;
        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 2;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                if(x == n-1 and y == n-1)
                    return level+1;
                for(int k=0; k<8; k++){
                    int newx = x + dx[k], newy = y + dy[k];
                    if(newx >= 0 and newy >= 0 and newx < n and newy < n and !grid[newx][newy]){
                        q.push({newx, newy});
                        grid[newx][newy] = 2;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};