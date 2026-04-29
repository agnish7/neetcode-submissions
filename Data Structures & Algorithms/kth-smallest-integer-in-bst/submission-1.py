# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        res = float('-inf')
        ctr = 0
        def traverse(node):
            nonlocal k
            nonlocal ctr
            if not node:
                return float('-inf')
            
            left = traverse(node.left)
            ctr += 1
            # print(node.val, ctr)
            if ctr == k:
                return node.val
            right = traverse(node.right)
            return max(left, right)

        return traverse(root)