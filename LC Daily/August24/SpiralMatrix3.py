# Spiral matrix 3
from typing import List
class Solution:
    def move(self, row, col, dir):
        dx, dy = 0, 0
        if dir == 0:
            dy += 1
        elif dir == 1:
            dx += 1
        elif dir == 2:
            dy -= 1
        elif dir == 3:
            dx -= 1
        return (dx, dy)

    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        visited = set()
        result = [[rStart, cStart]]
        visited.add((rStart, cStart))

        row, col = rStart, cStart
        dir = 0
        start = True
        while len(result) != rows*cols:
            # at each vertex we have two decisions to make
            dx_pll, dy_pll = self.move(row, col, dir)
            dx_perp, dy_perp = self.move(row, col, (dir+1)%4)

            if start:
                row, col, dir = dx_pll + row, dy_pll + col, dir
                start = False
            else:
                if (dx_perp+row, dy_perp+col) in visited:
                    row, col, dir = dx_pll + row, dy_pll + col, dir
                else:
                    row, col, dir = dx_perp + row, dy_perp + col, (dir+1)%4
            visited.add((row, col))
            if row >= 0 and row < rows and col >=0 and col < cols:
                    result.append([row, col])


        return result