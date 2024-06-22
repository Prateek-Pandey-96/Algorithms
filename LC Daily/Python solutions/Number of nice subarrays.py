# 1248. Count Number of Nice Subarrays
from typing import List
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        def helper(K):
            n = len(nums)
            total_subarrays = 0
            odd = 0
            i, j = 0, 0
            while j<n:
                if nums[j]%2 != 0:
                    odd += 1
                while(odd > K):
                    if nums[i]%2 != 0:
                        odd -= 1
                    i += 1
                total_subarrays += j-i+1
                j += 1
            return total_subarrays
        return helper(k)-helper(k-1)
