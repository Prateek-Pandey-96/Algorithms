# 386. Lexicographical Numbers
from typing import List
class TrieNode:
    def __init__(self, val):
        self.val = val
        self.children = [None]*10

    def insert(self, val):
        rep = []
        while val > 0:
            rep.append(val%10)
            val = val//10
        rep.reverse()

        crawl = self
        for digit in rep:
            if not crawl.children[int(digit)]:
                crawl.children[int(digit)] = TrieNode(int(digit))
            crawl = crawl.children[int(digit)]

    def traverseTrie(self, node, prev_value, result):

        for child in node.children:
            if child is not None:
                result.append(prev_value*10 + child.val)
                self.traverseTrie(child, prev_value*10 + child.val, result)
            else:
                continue


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        root = TrieNode(-1)
        for i in range(1, n+1):
            root.insert(i)

        result = []
        root.traverseTrie(root, 0, result)
        return result
        

# better solution

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        result = []
        def recursiveHelper(prev):
            for i in range(10):
                num = prev * 10 + i
                if num == 0:
                    continue
                if num > n:
                    return
                result.append(num)
                recursiveHelper(num)
        
        recursiveHelper(0)
        return result