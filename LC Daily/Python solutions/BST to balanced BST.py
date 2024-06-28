# 1382. Balance a Binary Search Tree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def createArray(self, root, arr):
        if root is None:
            return
        
        self.createArray(root.left, arr)
        arr.append(root.val)
        self.createArray(root.right, arr)
    
    def createBalancedBST(self, arr, l, r) -> TreeNode:
        if l==r:
            return TreeNode(arr[l])
        if l>r:
            return None

        mid = (l + r) // 2
        leftTree = self.createBalancedBST(arr, l, mid-1)
        rightTree = self.createBalancedBST(arr, mid+1, r)
        return TreeNode(arr[mid], leftTree, rightTree)


    def balanceBST(self, root: TreeNode) -> TreeNode:
        arr = []
        self.createArray(root, arr)
        return self.createBalancedBST(arr, 0, len(arr)-1)
