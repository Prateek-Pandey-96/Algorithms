# 1590. Make Sum Divisible by P
from typing import List
from collections import defaultdict
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums)

        target = total%p
        if target == 0:
            return 0
        
        curr_sum, min_len = 0, len(nums)
        position = defaultdict(int)
        position[0] = -1
        
        for i in range(len(nums)):
            num = nums[i]
            curr_sum += num
            rem = curr_sum % p
            req = (rem - target + p)%p

            if req in position:
                min_len = min(min_len, i-position[req])
            
            position[rem] = i
 
        return min_len if min_len != len(nums) else -1