# 2326. Spiral Matrix IV
from typing import List, Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        matrix = []
        for i in range(m):
            row = [-1]*n
            matrix.append(row)

        l, t, r, b = 0, 0, n-1, m-1
        while True: 
            flag = True
            idx = l
            while idx <= r:
                if head is None:
                    flag = False
                    break
                matrix[t][idx] = head.val
                head = head.next
                idx += 1
            t += 1
            if t > b:
                break
            
            idx = t
            while idx<=b:
                if head is None:
                    flag = False
                    break
                matrix[idx][r] = head.val
                head = head.next
                idx += 1
            r -= 1
            if r<l:
                break
            
            idx = r
            while idx >= l:
                if head is None:
                    flag = False
                    break
                matrix[b][idx] = head.val
                head = head.next
                idx -= 1
            b -= 1
            if b < t:
                break

            idx = b
            while idx >= t:
                if head is None:
                    flag = False
                    break
                matrix[idx][l] = head.val
                head = head.next
                idx -= 1
            l += 1
            if l > r:
                break
            if flag == False:
                break

        return matrix