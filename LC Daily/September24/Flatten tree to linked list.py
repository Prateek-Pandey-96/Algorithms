# 114. Flatten Binary Tree to Linked List
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        if root is None:
            return
        
        crawl = root
        while crawl:
            if crawl.left is not None:
                l, r = crawl.left, crawl.right
                l_crawler = l
                while l_crawler.right is not None:
                    l_crawler = l_crawler.right
                crawl.left = None
                crawl.right = l
                l_crawler.right = r
            crawl = crawl.right
        