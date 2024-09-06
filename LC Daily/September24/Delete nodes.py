# 3217. Delete Nodes From Linked List Present in Array
from typing import List, Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        nums_set = set(nums)
        crawler = head

        new_list_ptr = ListNode(-1)
        dummy_ptr = ListNode(-1)
        dummy_ptr.next = new_list_ptr
        while crawler is not None:
            if crawler.val not in nums_set:
                new_list_ptr.next = ListNode(crawler.val)
                new_list_ptr = new_list_ptr.next
            crawler = crawler.next

        return dummy_ptr.next.next
        