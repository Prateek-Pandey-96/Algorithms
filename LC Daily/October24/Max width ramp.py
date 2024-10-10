# 962. Maximum Width Ramp
from typing import List

class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n: int = len(nums)
        stack: List[int] = []

        ramp_width: int = 0
        for i in range(n):
            if len(stack) == 0 or nums[i]<nums[stack[-1]]:
                stack.append(i)
            else:
                start, end = 0, len(stack)-1
                idx = -1
                while start <= end:
                    mid = start + (end-start)//2
                    if nums[stack[mid]]<=nums[i]:
                        idx = mid
                        end = mid - 1
                    else:
                        start = mid + 1
                if idx!=-1:
                    ramp_width = max(ramp_width, i-stack[idx])
        
        return ramp_width