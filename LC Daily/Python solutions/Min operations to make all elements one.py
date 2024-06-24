# 3191. Minimum Operations to Make Binary Array Elements Equal to One I
from typing import List
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        flips, i = 0, 0
        while i < n-2:
            if nums[i] == 1:
                i += 1
            else:
                flips += 1
                nums[i] = 1
                nums[i+1] = 1 - nums[i+1]
                nums[i+2] = 1 - nums[i+2]
                i += 1
        
        if nums[n-2] == 1 and nums[n-1] == 1:
            return flips
        return -1