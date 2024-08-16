# 624. Maximum Distance in Arrays
from typing import List
class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        n, dist = len(arrays), 0
        start, end = arrays[0][0], arrays[0][-1]

        for i in range(1, n):
            if arrays[i][0] > end:
                end = arrays[i][-1]
                dist = max(dist, end-start)
            elif arrays[i][-1] < start:
                start = arrays[i][0]
                dist = max(dist, end-start)
            else:
                # intersection of two arrays
                dist = max(dist, arrays[i][-1]-start)
                dist = max(dist, end - arrays[i][0])
                end = max(end, arrays[i][-1])
                start = min(start, arrays[i][0])

        return dist
