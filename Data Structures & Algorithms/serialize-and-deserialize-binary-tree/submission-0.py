# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    def __init__(self):
        self.preorder_array = []
        self.nodes = []
        self.idx = 0

    def preorder(self, root):
        if not root:
            self.preorder_array.append('N')
            return

        self.preorder_array.append(str(root.val))
        self.preorder(root.left)
        self.preorder(root.right)

    def reconstruct(self):
        if self.nodes[self.idx] == 'N':
            self.idx += 1
            return None

        root = TreeNode(int(self.nodes[self.idx]))
        self.idx += 1
        root.left = self.reconstruct()
        root.right = self.reconstruct()

        return root
        

    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        self.preorder(root)
        return (",".join(self.preorder_array))
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        self.nodes = data.split(',')
        return self.reconstruct()