# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
from typing import List, Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        critical_points = []
        idx = 1
        
        prev = head
        head = head.next
        
        while head is not None:
            
            if head.next is not None:
                local_minima = prev.val > head.val and head.next.val > head.val
                local_maxima = prev.val < head.val and head.next.val < head.val
                if local_minima or local_maxima:
                    critical_points.append(idx)
            
            prev = head
            head = head.next
            idx += 1

        if len(critical_points) < 2:
            return [-1, -1]

        max_dist = critical_points[-1] - critical_points[0]

        min_dist = float("inf")
        for i in range(len(critical_points)-1):
            min_dist = min(min_dist, critical_points[i+1]-critical_points[i])
        
        if min_dist == float("inf"):
            return [max_dist, max_dist]
        return [min_dist, max_dist]