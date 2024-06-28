# 2285. Maximum Total Importance of Roads
from typing import List
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        # we will assign numbers in decreasing order of degree
        degree: List[int] = []
        for i in range(n):
            degree.append(0)
        
        for road in roads:
            degree[road[0]] += 1
            degree[road[1]] += 1
        
        degree.sort(reverse = True)
        imp: int = 0
        factor: int = n
        for i in range(n):
            imp += degree[i]*factor
            factor -= 1
        
        return imp
