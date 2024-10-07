from typing import List
from collections import defaultdict

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        freq = defaultdict(int)

        sum, result = 0, 0
        freq[sum] = 1

        for num in nums:
            sum += num
            rem = (sum+k)%k

            if rem in freq:
                result += freq[rem]
            
            freq[rem] += 1
        
        return result