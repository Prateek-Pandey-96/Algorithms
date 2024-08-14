# 1568. Minimum Number of Days to Disconnect Island
from copy import deepcopy
from typing import List

class Solution:
    m, n, timer = 0, 0, 0
    dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
    articulation_points = 0
    
    def find_island_count(self, grid, x, y) -> None:
        grid[x][y] = 0

        for i in range(4):
            newx, newy = x + self.dx[i], y + self.dy[i]
            if newx < 0 or newy < 0 or newx >= self.m or newy >= self.n or grid[newx][newy]==0:
                continue
            self.find_island_count(grid, newx, newy)

    def find_articulation_points(self, grid, row, col, par_row, par_col, visited, intime, mintime) -> None:
        visited[row][col] = True
        self.timer += 1
        intime[row][col], mintime[row][col] = self.timer, self.timer
        
        children = 0
        for i in range(4):
            newrow, newcol = row + self.dx[i], col + self.dy[i]
            if newrow < 0 or newcol < 0 or newrow >= self.m or newcol >= self.n or grid[newrow][newcol]==0:
                continue
            if not visited[newrow][newcol]:
                children += 1
                self.find_articulation_points(grid, newrow, newcol, row, col, visited, intime, mintime)
                mintime[row][col] = min(mintime[row][col], mintime[newrow][newcol])
                if mintime[newrow][newcol] >= intime[row][col] and not (par_row == -1 and par_col == -1):
                    self.articulation_points += 1
            elif not (newrow == par_row and newcol == par_col):
                mintime[row][col] = min(mintime[row][col], intime[newrow][newcol])
        
        if par_row == -1 and par_col == -1 and (children > 1 or children==0):
            self.articulation_points += 1

    def minDays(self, grid: List[List[int]]) -> int:
        copy_grid = deepcopy(grid)
        islands = 0
        self.m, self.n, self.timer = len(grid), len(grid[0]), 0

        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j]==1:
                    islands += 1
                    self.find_island_count(grid, i, j)

        if islands == 0 or islands > 1:
            return 0
        
        self.articulation_points = 0

        visited = [[False]*self.n for _ in range(self.m)]
        intime = [[0]*self.n for _ in range(self.m)]
        mintime = [[0]*self.n for _ in range(self.m)]


        for i in range(self.m):
            for j in range(self.n):
                if copy_grid[i][j]==1 and not visited[i][j]:
                    self.find_articulation_points(copy_grid, i, j, -1, -1, visited, intime, mintime)
                    break
        
        return 2 if self.articulation_points==0 else 1