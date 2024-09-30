# 2416. Sum of Prefix Scores of Strings
from typing import List
class TrieNode:
    def __init__(self, val: str):
        self.val = val
        self.count = 1
        self.children = [None] * 26
    
    def addWord(self, word):
        curr = self
        for ch in word:
            i = ord(ch)-ord('a')
            if not curr.children[i]:
                curr.children[i] = TrieNode(ch)
                curr = curr.children[i]
            else:
                curr.children[i].count += 1
                curr = curr.children[i]

    def getScore(self, word):
        curr = self
        score = 0
        for ch in word:
            i = ord(ch)-ord('a')
            score += curr.children[i].count
            curr = curr.children[i]
        return score

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        root = TrieNode("root")
        for word in words:
            root.addWord(word)
        
        result = []
        for word in words:
            result.append(root.getScore(word))

        return result
