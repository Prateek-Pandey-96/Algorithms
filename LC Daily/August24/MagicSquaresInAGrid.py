# 840. Magic Squares In Grid
from typing import List
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if m < 3 or n < 3:
            return 0
        
        count = 0
        for i in range(m-2):
            for j in range(n-2):
                # check diags
                if (grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2] != 15 or 
                grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != 15):
                    continue
                
                #  check row sum
                if (grid[i][j]+grid[i][j+1]+grid[i][j+2] != 15 or
                grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2] != 15 or
                grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2] != 15):
                    continue

                #  check col sum
                if (grid[i][j]+grid[i+1][j]+grid[i+2][j] != 15 or
                grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1] != 15 or
                grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2] != 15):
                    continue
                
                # check for all numbers to be distinct
                nums = set()
                issue = False
                for row in range(3):
                    for col in range(3):
                        if grid[i+row][j+col]>9 or grid[i+row][j+col]<1:
                            issue = True
                            break
                        nums.add(grid[i+row][j+col])
                    if issue:
                        break
                if len(nums) != 9 or issue:
                    continue

                count += 1

        return count