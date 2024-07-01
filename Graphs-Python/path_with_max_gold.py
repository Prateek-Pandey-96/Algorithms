# 1219. Path with Maximum Gold
from typing import List
class Solution:
    dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

    def dfs(self, grid: List[List[int]], x: int, y: int) -> int:
        gold = grid[x][y]
        temp = grid[x][y]
        grid[x][y] = 0

        additional_gold = 0
        for i in range(4):
            newx, newy = x + self.dx[i], y + self.dy[i]
            if newx >= 0 and newx < len(grid) and newy >= 0 and newy < len(grid[0]) and grid[newx][newy]!=0:
                additional_gold = max(additional_gold, self.dfs(grid, newx, newy))
        
        grid[x][y] = temp
        return gold + additional_gold

    def getMaximumGold(self, grid: List[List[int]]) -> int:
        max_gold = 0
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y]!=0:
                    max_gold = max(max_gold, self.dfs(grid, x, y))
        return max_gold