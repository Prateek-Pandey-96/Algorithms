# 2134. Minimum Swaps to Group All 1's Together II
from typing import List
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        count_one, n = 0, len(nums)
        for num in nums:
            if num==1:
                count_one += 1

        i, curr_count = 0, 0
        while i < count_one:
            if nums[i] == 1:
                curr_count += 1
            i += 1
        
        swaps = count_one-curr_count
        
        while i < n + count_one - 1:
            if nums[i%n] == 1:
                curr_count += 1
            if nums[i-count_one] == 1:
                curr_count -= 1
            swaps = min(swaps, count_one-curr_count)
            i += 1
        
        return swaps
