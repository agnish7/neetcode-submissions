# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        q = deque()
        q.append(root)

        res = []

        while q:
            size = len(q)

            for i in range(size):
                node = q[0]
                if node:
                    if node.left: q.append(node.left)
                    if node.right: q.append(node.right)
                if i == size - 1:
                    res.append(node.val)
                q.popleft()
            
        return res