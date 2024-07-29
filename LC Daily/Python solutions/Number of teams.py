# 1395. Count Number of Teams
from typing import List
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)

        type1, type2 = 0, 0
        for i in range(1, n-1):
            num = rating[i]
            smaller, larger = 0, 0
            for j in range(i):
                if rating[j]<num:
                    smaller += 1
            for k in range(i+1, n):
                if rating[k]>num:
                    larger += 1
            type1 += smaller * larger
        
        for i in range(1, n-1):
            num = rating[i]
            smaller, larger = 0, 0
            for j in range(i):
                if rating[j]>num:
                    larger += 1
            for k in range(i+1, n):
                if rating[k]<num:
                    smaller += 1
            type2 += smaller * larger
        return type1+type2