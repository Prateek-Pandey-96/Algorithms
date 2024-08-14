from typing import List
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m, n = len(matrix), len(matrix[0])
        
        # form the col wise prefix sum 
        for i in range(m):
            for j in range(1, n):
                matrix[i][j] += matrix[i][j-1]

        # find repeating sum with the help of hashing
        count = 0
        for col in range(n):
            for j in range(col, n):
                hashmap = {}
                hashmap[0] = 1        
                sum = 0
                for i in range(m):
                    sum += matrix[i][j] - (matrix[i][col-1] if col-1>=0 else 0)
                    if sum-target in hashmap:
                        count += hashmap[sum-target]

                    if sum in hashmap:
                        hashmap[sum] += 1
                    else:
                        hashmap[sum] = 1

        return count