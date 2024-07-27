# 2976. Minimum Cost to Convert String I
from typing import List
class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        # floyd warshall
        mat = []
        for i in range(26):
            row = [float("inf") for i in range(26)]
            mat.append(row)
        
        for i in range(26):
            mat[i][i] = 0

        n = len(original)
        for i in range(n):
            f, t, c = original[i], changed[i], cost[i]
            mat[ord(f)-ord('a')][ord(t)-ord('a')] = min(c, mat[ord(f)-ord('a')][ord(t)-ord('a')])
        
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j])
        
        conversion_cost = 0
        for i in range(len(source)):
            if mat[ord(source[i])-ord('a')][ord(target[i])-ord('a')] == float("inf"):
                return -1
            conversion_cost += mat[ord(source[i])-ord('a')][ord(target[i])-ord('a')]
        return conversion_cost
        