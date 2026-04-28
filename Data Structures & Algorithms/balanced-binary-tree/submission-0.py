# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        isbalance = True
        def traverse(node):
            nonlocal isbalance
            if not node:
                return 0

            left = traverse(node.left)
            right = traverse(node.right)

            if abs(left - right) > 1:
                isbalance = False
            return 1 + max(left, right)

        
        traverse(root)
        return isbalance