# 1192. Critical Connections in a Network
# Bridges in a graph
from typing import List
class Solution:
    def dfs(self, src, par, graph, visited, in_time, low_time, result, timer) -> None:
        visited[src] = True
        in_time[src], low_time[src] = timer, timer

        for child in graph[src]:
            if child == par:
                continue
            if not visited[child]:
                self.dfs(child, src, graph, visited, in_time, low_time, result, timer+1)
                low_time[src] = min(low_time[src], low_time[child])
                if low_time[child] > in_time[src]:
                    result.append([src, child])
            else:
                low_time[src] = min(low_time[src], low_time[child])

    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph = {i: [] for i in range(n)}
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        in_time = [0] * n
        low_time = [0] * n

        result = []
        self.dfs(0, -1, graph, visited, in_time, low_time, result, 0)
        return result
        