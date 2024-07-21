# 2392. Build a Matrix With Conditions
from typing import List
from collections import deque
class Solution:
    def dfs(self, src, graph, visited):
        visited[src] = 1
        visited[src] = 2

        for child in graph[src]:
            if visited[child] == 0:
                flag = self.dfs(child, graph, visited)
                if flag:
                    return True
            elif visited[child] == 2:
                return True
        
        visited[src] = 1
        return False

    def is_cyclic(self, k, conditions):
        graph = {i: [] for i in range(k)}
        visited = [0 for i in range(k)]
        for row in conditions:
            graph[row[1]-1].append(row[0]-1)
        
        for i in range(k):
            if visited[i]==0:
                flag = self.dfs(i, graph, visited)
                if flag:
                    return True
        return False

    def topo_sort(self, k, conditions):
        graph = {i: [] for i in range(k)}
        indegree = [0 for i in range(k)]
        for col in conditions:
            graph[col[1]-1].append(col[0]-1)
            indegree[col[0]-1] += 1
        
        result = []
        queue = deque()
        for i in range(k):
            if indegree[i] == 0:
                queue.append(i)
        
        while queue:
            size = len(queue)
            while size > 0:
                src = queue.popleft()
                result.append(src)
                for child in graph[src]:
                    indegree[child] -= 1
                    if indegree[child] == 0:
                        queue.append(child)
                size -= 1
        return result
            
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        # no cycle should be present both row-wise and col-wise
        if self.is_cyclic(k, rowConditions) or self.is_cyclic(k, colConditions):
            return []
        
        topo_sorted_row_con = self.topo_sort(k, rowConditions)
        topo_sorted_col_con = self.topo_sort(k, colConditions)
        print(topo_sorted_col_con)

        matrix = []
        for i in range(k):
            row = [0 for i in range(k)]
            matrix.append(row)
        
        idx = 0
        for i in range(k):
            matrix[k-1-i][0] = topo_sorted_row_con[idx]+1
            idx += 1

        topo_sorted_col_con_map = {}
        idx = 0
        for i in range(k):
            topo_sorted_col_con_map[topo_sorted_col_con[k-i-1]+1] = idx
            idx += 1

        for i in range(k):
            col = topo_sorted_col_con_map[matrix[i][0]]
            matrix[i][col] = matrix[i][0]
            if col != 0:
                matrix[i][0] = 0
        
        return matrix