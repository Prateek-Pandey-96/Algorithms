# 959. Regions Cut By Slashes
from typing import List
class DSU:
    def __init__(self, n):
        self.n = n
        self.rank = [0] * n
        self.parent = [i for i in range(n)]
    
    def find_parent(self, a):
        if self.parent[a] == a:
            return a
        self.parent[a] = self.find_parent(self.parent[a])
        return self.parent[a]
    
    def do_union(self, a, b):
        par_a = self.find_parent(a)
        par_b = self.find_parent(b)

        if self.rank[par_a] > self.rank[par_b]:
            self.parent[par_b] = par_a
        elif self.rank[par_b] > self.rank[par_a]:
            self.parent[par_a] = par_b
        else:
            self.parent[par_a] = par_b
            self.rank[par_a] += 1

class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        m, regions = len(grid), 1
        
        dsu = DSU((m+1)*(m+1))
        for i in range(m):
            dsu.do_union(i, i+1)
            dsu.do_union(m*(m+1)+i, m*(m+1)+i+1)

        for i in range(0, m*m, m+1):
            dsu.do_union(i, i+m+1)
            dsu.do_union(i+m, i+m+m+1)

        for row_num in range(m):
            row = grid[row_num]
            for i in range(len(row)):
                if row[i]!=' ':
                    if row[i]=='/':
                        pointa = row_num*(m+1) + (i+1)
                        pointb = pointa + m
                    else:
                        pointa = row_num*(m+1) + i 
                        pointb = pointa + (m+2)
                    para, parb = dsu.find_parent(pointa), dsu.find_parent(pointb)
                    if para == parb:
                        regions += 1
                    else:
                        dsu.do_union(pointa, pointb)
        return regions
