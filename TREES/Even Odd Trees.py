# 1609. Even Odd Tree

from collections import deque
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        queue = deque()
        queue.append(root)
        level = -1
        
        while queue:
            size = len(queue)
            level += 1
            temp = []
            for i in range(size):
                curr = queue.popleft()
                temp.append(curr.val)

                if level%2 == 0:
                    if temp[-1]%2 == 0:
                        return False
                    if len(temp)>=2 and temp[-1]<=temp[-2]:
                        return False
                else:
                    if temp[-1]%2 != 0:
                        return False
                    if len(temp)>=2 and temp[-1]>=temp[-2]:
                        return False

                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)

        return True