# 1310. XOR Queries of a Subarray
from typing import List

class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        for i in range(1, n):
            arr[i] = arr[i]^arr[i-1]
        
        result = []

        for x, y in queries:
            xor_till_y = arr[y]
            xor_till_x = arr[x-1] if x >= 1 else 0
            result.append(xor_till_y ^ xor_till_x)
        return result