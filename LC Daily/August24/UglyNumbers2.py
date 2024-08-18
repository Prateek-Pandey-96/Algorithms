# 264 Ugly Number 2
from heapq import heapify, heappop, heappush
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        heap = [1]
        heapify(heap)
        
        seen = set()
        seen.add(1)
        
        result = 0
        for i in range(n):
            top = heappop(heap)
            result = top

            if top*2 not in seen:
                heappush(heap, top*2)
                seen.add(top*2)
            if top*3 not in seen:
                heappush(heap, top*3)
                seen.add(top*3)
            if top*5 not in seen:
                heappush(heap, top*5)
                seen.add(top*5)
        
        return result
