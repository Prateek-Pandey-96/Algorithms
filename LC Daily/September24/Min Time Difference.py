# 539. Minimum Time Difference
from typing import List
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # convert the timestamps to minutes
        minute_array = []
        for time in timePoints:
            hours = int(time[:2])
            minutes = int(time[3:])
            total_min = hours*60+minutes
            minute_array.append(total_min)
        
        # sort the array
        minute_array.sort()
        n = len(timePoints)
        ans = float("inf")
        
        # find diff between adjacent elements
        for i in range(0, n):
            diff = abs(minute_array[(i+1)%n]-minute_array[i])
            ans = min(ans, diff)
            ans = min(ans, 1440 - diff)
        
        return ans
