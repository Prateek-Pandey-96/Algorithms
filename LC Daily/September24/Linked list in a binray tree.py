# 1367. Linked List in Binary Tree
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def dfs(self, head, root):
        # if list ends
        if head is None:
            return True
        
        # if tree reaches end
        if root is None:
            return False

        if head.val != root.val:
            return False
        
        return self.dfs(head.next, root.left) or self.dfs(head.next, root.right)

    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        # if list ends
        if head is None:
            return True
        
        # if tree reaches end
        if root is None:
            return False
        
        checkLeft = self.isSubPath(head, root.left)
        checkRight = self.isSubPath(head, root.right)

        return checkLeft or checkRight or self.dfs(head, root)
