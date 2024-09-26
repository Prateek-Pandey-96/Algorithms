# 127. Word Ladder

from collections import deque
from typing import List

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def change_char(s, idx, ch):
            ls = []
            for i in range(len(s)):
                ls.append(s[i])
            ls[idx] = ch
            return ''.join(ls)

        queue = deque()
        queue.append(beginWord)

        hops = 0
        word_set = set(wordList)
        word_len = len(beginWord)

        while queue:
            size = len(queue)
            hops += 1
            for i in range(size):
                
                curr = queue.popleft()
                if curr == endWord:
                    return hops

                for i in range(word_len):
                    ch = curr[i]
                    for j in range(26):
                        new_ch = chr(j+ord('a'))
                        
                        if new_ch == ch:
                            continue
                        new_str = change_char(curr, i, new_ch)
                        
                        if new_str in word_set:
                            queue.append(new_str)
                            word_set.remove(new_str)  
        
        return 0

