# 1497. Check If Array Pairs Are Divisible by k
from collections import defaultdict
from typing import List
class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        n = len(arr)
        freq = defaultdict(int)
        
        for num in arr:
            mod = (num%k + k)%k
            freq[mod] += 1

        if freq[0]%2:
            return False

        for i in range(1, k):
            if freq[i]!=freq[k-i]:
                return False

        return True

        
