# 1289. Minimum Falling Path Sum II
from typing import List
class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n==1:
            return grid[0][0]
        
        for i in range(1, n):
            # keep min before and after the current element
            left, right = [float("inf")]*n, [float("inf")]*n
            for k in range(1, n):
                left[k] = min(left[k-1], grid[i-1][k-1])
            for k in range(n-2, -1, -1):
                right[k] = min(right[k+1], grid[i-1][k+1])
            
            for j in range(n):
                grid[i][j] += min(left[j], right[j])
        
        return min(grid[n-1])
