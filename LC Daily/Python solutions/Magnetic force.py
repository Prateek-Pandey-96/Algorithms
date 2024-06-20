# 1552. Magnetic Force Between Two Balls
from typing import List
class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        
        def isPossible(limit: int):
            placed = 1
            rng = position[0] + limit  
            for p in position[1:]:
                if p < rng:
                    continue
                placed += 1
                rng = p + limit
                if placed == m:
                    break
            return placed == m
        
        low, high = 1, 10**9
        max_minforce = float("-inf")
        while low <= high:
            mid = low + (high-low)//2
            if isPossible(mid):
                max_minforce = mid
                low = mid+1
            else:
                high = mid-1
        return max_minforce
        
            

