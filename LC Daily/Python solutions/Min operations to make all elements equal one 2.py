# 3192. Minimum Operations to Make Binary Array Elements Equal to One II
from typing import List
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # we need to utilize flip count here
        flips, i = 0, 0
        n = len(nums)
        while i<n:
            # even flips
            if flips%2 == 0:
                if nums[i]==1:
                    i += 1
                else:
                    flips += 1
                    i += 1
            # odd flips
            else:
                if nums[i]==1:
                    flips += 1
                    i += 1
                else:
                    i += 1
        return flips
