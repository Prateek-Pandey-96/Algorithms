# 2419. Longest Subarray With Maximum Bitwise AND
from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ''' 
        hint :- bitwise and of two numbers 
        is always less than the greater number
        '''

        # step-1 :- max element in the array is target bitwise and
        required_and = 0
        for num in nums:
            required_and = max(required_and, num)

        # step-2 :- find max consequtive number
        result = 1
        count = 0
        for num in nums:
            if num == required_and:
                if count == 0:
                    count = 1
                else:
                    count += 1
            else:
                result = max(result, count)
                count = 0
        
        # step-3 :- consider last consequtive subarray
        result = max(result, count)
        return result
        
    