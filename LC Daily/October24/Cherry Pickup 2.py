# 1463. Cherry Pickup II
from typing import List
from functools import lru_cache

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        @lru_cache
        def dfs(row, col1, col2):
            if row == m:
                return 0
            
            cherries = 0
            if col1 == col2:
                cherries += grid[row][col1]
            else:
                cherries += grid[row][col1] + grid[row][col2]
            
            additional_cherries = 0
            for i in range(-1, 2):
                for j in range(-1, 2):
                    new_col1 = col1+i
                    new_col2 = col2+j
                    if new_col1 >= 0 and new_col1 < n and new_col2 >= 0 and new_col2 < n:
                        additional_cherries = max(additional_cherries, dfs(row+1, new_col1, new_col2))
            
            return cherries + additional_cherries

        return dfs(0, 0, n-1)