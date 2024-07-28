# 1202. Smallest String With Swaps
from typing import List
class UnionFind:
    def __init__(self, n):
        self.n = n
        self.rank = [0] * n
        self.parent = [i for i in range(n)]
    
    def find_parent(self, a):
        if self.parent[a] != a:
            self.parent[a] = self.find_parent(self.parent[a])
        return self.parent[a]
    
    def do_union(self, a, b):
        par_a = self.find_parent(a)
        par_b = self.find_parent(b)
        if par_a == par_b:
            return 
        if self.rank[par_a] > self.rank[par_b]:
            self.parent[par_b] = par_a
        elif self.rank[par_b] > self.rank[par_a]:
            self.parent[par_a] = par_b
        else:
            self.parent[par_b] = par_a
            self.rank[par_a] += 1

class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        n = len(s)
        unionfind = UnionFind(n)
        for pair in pairs:
            unionfind.do_union(pair[0], pair[1])

        mapping = {}
        for i in range(n):
            par = unionfind.find_parent(i)
            if par in mapping:
                mapping[par].append(i)
            else:
                mapping[par] = [i]

        res = ["" for i in range(n)]
        for key, value in mapping.items():
            temp = []
            for idx in value:
                temp.append(s[idx])
            temp.sort()
            temp_str = "".join(temp)
            
            i = 0
            for idx in value:
                res[idx] = temp_str[i]
                i += 1
        
        return "".join(res)
        
        