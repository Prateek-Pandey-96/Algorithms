from functools import cache
from typing import List
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        '''
        Start from 0,0 and go to m-1, m-1 through two paths
        
        '''
        m = len(grid)

        @cache
        def dfs(row1, col1, row2):
            col2 = row1 + col1 - row2
            # whenever any path goes outside grid
            if row1 >= m or row2 >= m or col1 >= m or col2 >= m:
                return float("-inf")
            
            # whenever any path land on a thorn
            if grid[row1][col1] == -1 or grid[row2][col2] == -1:
                return float("-inf")

            if row1 == m-1 and row2 == m-1 and col1 == m-1 and col2 == m-1:
                return grid[row1][col1]  

            cherries = grid[row1][col1]
            if row1 != row2 or col1 != col2:
                cherries += grid[row2][col2]
            
            option1 = dfs(row1 + 1, col1, row2 + 1)
            option2 = dfs(row1, col1 + 1, row2 + 1)
            option3 = dfs(row1 + 1, col1, row2)
            option4 = dfs(row1, col1 + 1, row2)

            extra_cherries = max(option1, option2, option3, option4)
            if extra_cherries == float("-inf"):
                return float("-inf")
            
            return cherries + extra_cherries

        return max(0, dfs(0, 0, 0))
