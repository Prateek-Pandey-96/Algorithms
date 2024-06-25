# 1038. Binary Search Tree to Greater Sum Tree
# reverse inorder needs to be done as all the 
# nodes will be traversed in descending order
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        prev_sum = [0]
        def helper(root: TreeNode):
            if root is None:
                return
            helper(root.right)
            root.val += prev_sum[0]
            prev_sum[0] = root.val
            helper(root.left)
            return
        
        helper(root)
        return root