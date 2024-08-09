# 2251. Number of Flowers in Full Bloom
from typing import List
from heapq import heappush, heappop
class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        # min heap + sorting should be the way to go
        # line sweep will give TLE
        people_idx = [(people[i], i) for i in range(len(people))]
        flowers.sort(), people_idx.sort()
        heap, result = [], [0 for i in range(len(people))]
        
        idx, n = 0, len(flowers)
        for person, i in people_idx:
            # add all that flowers that starts blooming before the person arrives
            while idx < n and flowers[idx][0] <= person:
                heappush(heap, (flowers[idx][1], flowers[idx][0]))
                idx += 1

            # remove all the flowers that ends blooming before the person arrives
            while heap:
                top = heappop(heap)
                if top[0] < person:
                    continue
                else:
                    heappush(heap, top)
                    break
            result[i] = len(heap)

        return result
            

