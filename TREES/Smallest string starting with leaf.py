# 988. Smallest String Starting From Leaf

from collections import deque
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.result = None

    def getChar(self, num):
        return chr(num+ord('a'))
    
    def preorder(self, node, curr):
        if node is None:
            return
        
        if node.left is None and node.right is None:
            curr.append(self.getChar(node.val))
            temp = "".join(curr)
            temp = temp[::-1]
            if self.result is None or temp < self.result:
                self.result = temp
            curr.pop()
            return 
        
        curr.append(self.getChar(node.val))
        self.preorder(node.left, curr)
        self.preorder(node.right, curr)
        curr.pop()

    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.result = None
        self.preorder(root, [])
        return self.result
