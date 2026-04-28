# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        good_nodes = 0

        # prev_nodes, root, root.left, root right


        def traverse(max_node_val, node):
            if not node:
                return
            nonlocal good_nodes

            # print(node.val, end = ": ")
            # for n in prev_nodes:
            #     print(n.val, end = " ")
            # print("")

            if max_node_val <= node.val:
                good_nodes += 1

            max_node_val = max(node.val, max_node_val)
            tmp = max_node_val
            traverse(max_node_val, node.left)
            traverse(tmp, node.right)
            max_node_val = tmp

        traverse(float('-inf'), root)

        return good_nodes
            