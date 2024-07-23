# 1636. Sort Array by Increasing Frequency
from typing import List
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq = {}
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        
        grouped = []
        for key, value in freq.items():
            grouped.append((key, value))
        
        grouped = sorted(grouped, key = lambda x: (x[1], -x[0]))
        
        result = []
        for grouped_pair in grouped:
            num, f = grouped_pair
            while f > 0:
                result.append(num)
                f -= 1
        
        return result