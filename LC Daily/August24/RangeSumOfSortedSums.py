# 1508. Range Sum of Sorted Subarray Sums
from typing import List
class Solution:
    mod = 1000000007
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        sums = []
        for i in range(n):
            sum = 0
            for j in range(i, n):
                sum += nums[j]
                sums.append(sum)
        
        sums.sort()

        result = 0
        for i in range(left-1, right):
            result = (result + sums[i])%self.mod
        
        return result