# 725. Split Linked List in Parts
from typing import List, Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def getLength(self, head) -> int:
        curr = head
        l = 0
        while curr is not None:
            curr = curr.next
            l += 1
        return l

    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        l = self.getLength(head)
        
        part_size = l//k
        parts = [part_size]*k

        extra = l%k
        idx = 0
        while extra != 0:
            parts[idx] += 1
            extra -= 1
            idx += 1

        result = []
        
        for i in range(k):
            crawl = head
            
            req_len = parts[i]
            if req_len == 0:
                result.append(None)
                continue

            req_len -= 1
            while req_len>0:
                crawl = crawl.next
                req_len -= 1
            new_start = crawl.next
            crawl.next = None
            result.append(head)
            head = new_start
        
        return result