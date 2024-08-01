from typing import Optional

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
class Solution:
    path_a, path_b = "", ""
    def dfs(self, node: TreeNode, curr_path, val: int, is_src: bool):
        if node is None:
            return
        
        if node.val == val:
            if is_src == True:
                self.path_a = "".join(curr_path)
            else:
                self.path_b = "".join(curr_path)
            return

        curr_path.append('L')
        self.dfs(node.left, curr_path, val, is_src)
        curr_path.pop()

        curr_path.append('R')
        self.dfs(node.right, curr_path, val, is_src)
        curr_path.pop()

    def get_lca(self, root: TreeNode, val1: int, val2: int) -> TreeNode:
        if root is None:
            return None
        if root.val == val1 or root.val == val2:
            return root
        
        left_decision = self.get_lca(root.left, val1, val2)
        right_decision = self.get_lca(root.right, val1, val2)
        
        if left_decision and right_decision:
            return root
        return left_decision if right_decision is None else right_decision

    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        lca = self.get_lca(root, startValue, destValue)
        self.dfs(lca, [], startValue, True)
        self.dfs(lca, [], destValue, False)

        i, j = 0, 0
        m, n = len(self.path_a), len(self.path_b)
        result = ""
        while i<m and j<n:
            if self.path_a[i] == self.path_b[j]:
                i += 1
                j += 1
            else:
                break
        while i<m:
            result += "U"
            i += 1
        while j<n:
            result += self.path_b[j]
            j += 1
        
        return result

