# 1631. Path With Minimum Effort

from heapq import heappush, heappop

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
        m, n = len(heights), len(heights[0])

        heap = []
        diff = [[float("inf") for _ in range(n)] for _ in range(m)]

        heappush(heap, [0, 0, 0])
        diff[0][0] = 0
        
        while heap:
            effort, x, y = heappop(heap)
            if x == m-1 and y == n-1:
                return effort

            for i in range(4):
                newx, newy = x + dx[i], y + dy[i]
                if newx < 0 or newy < 0 or newx >= m or newy >= n:
                    continue
                new_effort = max(abs(heights[newx][newy] - heights[x][y]), effort)
                if new_effort >= diff[newx][newy]:
                    continue
                heappush(heap, [new_effort, newx, newy])
                diff[newx][newy] = new_effort
        
        return -1