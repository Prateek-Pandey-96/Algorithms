class Solution {
public:

    bool isPossible(vector<vector<int>>& matrix, int factor, vector<vector<bool>>& visited, int x, int y){
        int m = matrix.size();
        if(x == m-1 and y == m-1)
            return true;
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        visited[x][y] = true;
        for(int i=0; i<4; i++){
            int newx = x + dx[i], newy = y + dy[i];
            if(newx >= 0 and newx < m and newy >= 0 and newy < m and matrix[newx][newy]>=factor and !visited[newx][newy])
                if(isPossible(matrix, factor, visited, newx, newy))
                    return true;
        }

        return false;
    }
    // we want the path to be as away from thieves as possible
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // bfs to find manhattan distance of each cell
        int m = grid.size();
        if(grid[0][0]==1 || grid[m-1][m-1]==1)
            return 0;
        queue<pair<int, int>> q;
        vector<vector<int>> matrix(m, vector<int>(m, -1));
        for(int i=0; i<m; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]==1)
                    q.push({i, j}), matrix[i][j] = 0;
        int level = 0;
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        while(!q.empty()){
            int size = q.size();
            level++;
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int newx = x+dx[i], newy = y+dy[i];
                    if(newx >= 0 and newx < m and newy >= 0 and newy < m and matrix[newx][newy]==-1)
                    {
                        q.push({newx, newy});
                        matrix[newx][newy]=level;
                    }
                }
            }
        }

        // now apply binary search on safeness factor from 0 to level
        int safeness_factor = -1, low = 0, high = level;
        while(low <= high){
            int mid = low + (high-low)/2;
            vector<vector<bool>> visited(m, vector<bool>(m, false));
            if(isPossible(matrix, mid, visited, 0, 0) and matrix[0][0]>=mid){
                safeness_factor = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return safeness_factor;
    }
};