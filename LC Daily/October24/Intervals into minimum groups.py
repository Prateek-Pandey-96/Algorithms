# 2406. Divide Intervals Into Minimum Number of Groups
from typing import List
from collections import defaultdict
class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        #  line sweep O(10^6)
        # n = len(intervals)
        # arr = [0] * 1000005

        # for start, end in intervals:
        #     arr[start] += 1
        #     arr[end+1] -= 1
        
        # result = 1
        # for i in range(1, len(arr)):
        #     arr[i] += arr[i-1]
        #     result = max(result, arr[i])
        
        # return result
        # reduced time and space O(N) time and O(2*N) space
        hashmap = defaultdict(int)
        for start, end in intervals:
            hashmap[start] += 1
            hashmap[end+1] -= 1
        
        result = 1
        counter = 0
        for _, value in sorted(hashmap.items()):
            counter += value
            result = max(result, counter)
        
        return result
