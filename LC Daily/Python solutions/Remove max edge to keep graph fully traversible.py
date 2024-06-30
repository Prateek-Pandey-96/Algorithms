# 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
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
            self.rank[par_a] += 1
        elif self.rank[par_b] > self.rank[par_a]:
            self.parent[par_a] = par_b
            self.rank[par_b] += 1
        else:
            self.parent[par_a] = par_b
            self.rank[par_a] += 1
        self.n -= 1
    
    def is_connected(self):
        return self.n==1
    
class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        alice_dsu = DSU(n)
        bob_dsu = DSU(n)
        count = 0
        
        for edge in edges:
            t, u, v = edge
            if t == 3:
                par_a = alice_dsu.find_parent(u-1)
                par_b = alice_dsu.find_parent(v-1)
                if par_a != par_b:
                    alice_dsu.do_union(u-1, v-1)
                    bob_dsu.do_union(u-1, v-1)
                else:
                    count += 1
        
        for edge in edges:
            t, u, v = edge
            if t == 1:
                par_a = alice_dsu.find_parent(u-1)
                par_b = alice_dsu.find_parent(v-1)
                if par_a != par_b:
                    alice_dsu.do_union(u-1, v-1)
                else:
                    count += 1
            elif t == 2:
                par_a = bob_dsu.find_parent(u-1)
                par_b = bob_dsu.find_parent(v-1)
                if par_a != par_b:
                    bob_dsu.do_union(u-1, v-1)
                else:
                    count += 1
        
        return count if alice_dsu.is_connected() and bob_dsu.is_connected() else -1