// 778. Swim in Rising Water

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        while(!minHeap.empty()){
            pair<int, pair<int, int>> top = minHeap.top();
            minHeap.pop();
            int hmax = top.first, x = top.second.first, y = top.second.second;
            if(x == n-1 and y == n-1)
                return hmax;
            
            for(int i=0; i<4; i++){
                int newx = x+dx[i], newy = y+dy[i];
                if(newx < 0 || newx >= n || newy < 0 || newy >= n)
                    continue;
                if(visited[newx][newy])
                    continue;
                int newh = grid[newx][newy];
                minHeap.push({max(newh, hmax), {newx, newy}});
                visited[newx][newy] = true;
            }
        }

        return -1;
    }
};