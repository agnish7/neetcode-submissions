# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        inorder_idx = {val: i for i, val in enumerate(inorder)}
        i = 0

        def build(l, r):
            nonlocal i
            if l > r:
                return None
            
            m = inorder_idx[preorder[i]]
            root = TreeNode(preorder[i])
            i += 1
            left = build(l, m - 1)
            right = build(m + 1, r)

            root.left = left
            root.right = right

            return root

        return build(0, len(preorder) - 1)

            