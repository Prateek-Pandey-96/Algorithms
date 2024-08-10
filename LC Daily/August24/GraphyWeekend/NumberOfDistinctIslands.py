from typing import List
class Solution:
    dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
    
    def dfs(self, grid, x, y, path, x0, y0) -> None:
        grid[x][y]=0
        path.append(str(x-x0) + str(y-y0))
        
        for i in range(4):
            newx, newy = x + self.dx[i], y + self.dy[i]
            if newx >= 0 and newy >= 0 and newx < len(grid) and newy < len(grid[0]) and grid[newx][newy]==1:
                self.dfs(grid, newx, newy, path, x0, y0)

    def countDistinctIslands(self, grid : List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        islands = set()
        
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    path = []
                    self.dfs(grid, i, j, path, i, j)
                    islands.add("".join(path))
        
        return len(islands)