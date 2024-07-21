# 1605. Find Valid Matrix Given Row and Column Sums
from typing import List
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)

        # create an empty matrix
        matrix = []
        for i in range(m):
            row = [0 for i in range(n)]
            matrix.append(row)

        # justify the row sum
        for i in range(m):
            matrix[i][0] = rowSum[i]

        # adjust col sum in a greedy way
        for j in range(n-1):
            # get curr col sum
            col_sum = 0
            for i in range(m):
                col_sum += matrix[i][j]
            # excess
            diff = col_sum - colSum[j]
            
            # adjust
            for i in range(m):
                if diff == 0:
                    break
                if diff > 0:
                    if diff >= matrix[i][j]:
                        matrix[i][j+1] = matrix[i][j]
                        diff -= matrix[i][j]
                        matrix[i][j] = 0
                    else:
                        matrix[i][j+1] =  diff
                        matrix[i][j] -= diff
                        diff = 0   
        
        return matrix


       