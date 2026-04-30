# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        
        def dfs(node):
            if not node:
                return float('-inf'), float('-inf')

            l_inc, l_exc = dfs(node.left)
            r_inc, r_exc = dfs(node.right)

            return max(l_inc + node.val, node.val + r_inc, node.val), max(l_inc + node.val + r_inc, l_exc, r_exc, l_inc, r_inc)
        
        inc, exc = dfs(root)

        return max(inc, exc)

        