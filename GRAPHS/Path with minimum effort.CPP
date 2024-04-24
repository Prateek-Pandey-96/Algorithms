// 1631. Path With Minimum Effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        // effort for starting cell is zero
        diff[0][0] = 0;
        minHeap.push({0, {0, 0}});

        /*Dijkstra's algorithm*/
        while(!minHeap.empty()){
            pair<int, pair<int, int>> top = minHeap.top();
            minHeap.pop();
            
            int effort = top.first, x = top.second.first, y = top.second.second;
            if(x == m-1 and y == n-1)
                return effort;
            
            for(int i=0; i<4; i++){
                int newx = x + dx[i], newy = y + dy[i];
                if(newx >= 0 and newy >= 0 and newx < m and newy < n){
                    int newEffort = max(abs(heights[newx][newy] - heights[x][y]), effort);
                    if(newEffort < diff[newx][newy])
                    {
                        diff[newx][newy] = newEffort;
                        minHeap.push({max(newEffort, effort), {newx, newy}});
                    }
                }
            }
        }
        // unreachable code
        return -1;
    }
};