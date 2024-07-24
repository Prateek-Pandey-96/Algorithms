# 1291. Sequential Digits
from typing import List
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        result, mn, mx = [], 10, 1000000000
        for i in range(1,10):
            num = 0
            for digit in range(i,10):
                num = num*10 + digit
                if num < mn:
                    continue
                if num > mx:
                    break
                if num <= high and num >= low:
                    result.append(num)
        
        return sorted(result)
