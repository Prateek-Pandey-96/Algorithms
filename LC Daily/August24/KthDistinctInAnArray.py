# 2053. Kth Distinct String in an Array
from typing import List
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        freq = {}
        for s in arr:
            if s in freq:
                freq[s] += 1
            else:
                freq[s] = 1

        pos = 0
        for key, val in freq.items():
            if val == 1:
                pos += 1
            if pos == k:
                return key
        
        return ""