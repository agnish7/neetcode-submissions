# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        good_nodes = []

        # prev_nodes, root, root.left, root right


        def traverse(prev_nodes, node):
            if not node:
                return
            nonlocal good_nodes

            # print(node.val, end = ": ")
            # for n in prev_nodes:
            #     print(n.val, end = " ")
            # print("")

            if all(n.val <= node.val for n in prev_nodes):
                good_nodes.append(node)

            prev_nodes.append(node)
            tmp = prev_nodes
            traverse(prev_nodes, node.left)
            traverse(tmp, node.right)
            prev_nodes.pop()

        traverse([], root)

        return len(good_nodes)
            