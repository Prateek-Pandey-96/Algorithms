# 41. First Missing Positive
from typing import List
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):            
            while nums[i]!=i+1 and nums[i] > 0 and nums[i] <= n:
                temp = nums[i]
                to_idx = temp - 1
                if nums[to_idx]==temp:
                    break
                nums[i] = nums[to_idx]
                nums[to_idx] = temp
        
        for i in range(n):
            if i+1 != nums[i]:
                return i+1
        return n+1
