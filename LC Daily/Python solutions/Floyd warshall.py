# 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
from typing import List
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # adjacency matrix
        graph = []
        for i in range(n):
            row = [float("inf") for i in range(n)]
            graph.append(row)
        
        for i in range(n):
            graph[i][i] = 0

        for edge in edges:
            u, v, w = edge
            graph[u][v] = w
            graph[v][u] = w
        
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])

        city, neighbours = -1, float("inf")

        for i in range(n):
            count = 0
            for j in range(n):
                if i!=j and graph[i][j] <= distanceThreshold:
                    count += 1
            if count <= neighbours:
                neighbours = count
                city = i

        return city

