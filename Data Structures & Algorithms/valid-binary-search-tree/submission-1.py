# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        isBST = True
        def traverse(node):
            nonlocal isBST
            if not node:
                return float('inf'), float('-inf')
            nonlocal isBST

            min_left, max_left = traverse(node.left)
            min_right, max_right = traverse(node.right)

            # print(min_left, max_left, node.val, min_right, max_right)

            if not (max_left < node.val < min_right):
                isBST = False

            min_curr = min(node.val, min(min_left, min_right))
            max_curr = max(node.val, max(max_left, max_right))

            return min_curr, max_curr

        traverse(root)

        return isBST