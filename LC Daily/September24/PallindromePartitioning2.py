from functools import lru_cache
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        
        @lru_cache
        def isPallindrome(l: int, h: int) -> bool:
            while l<h:
                if s[l]==s[h]:
                    l += 1
                    h -= 1
                else:
                    return False
            return True
        
        @lru_cache
        def partition(low, high):
            # string with length 0
            if low >= high:
                return 0
        
            # string already a pallindrome
            if isPallindrome(low, high):
                return 0

            min_cuts = high-low
            for idx in range(low, high):
                if isPallindrome(low, idx):
                    min_cuts = min(min_cuts, 1 + partition(idx+1, high))
            return min_cuts
        
        return partition(0, n-1)