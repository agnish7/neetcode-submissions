"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        visited = set()

        node_map = {}

        def dfs(node):

            if node in visited:
                return

            visited.add(node)

            node_map[node] = Node(node.val)

            for nei in node.neighbors:
                dfs(nei)
        
        dfs(node)

        for n, n_copy in node_map.items():
            for nei in n.neighbors:
                n_copy.neighbors.append(node_map[nei])



        return node_map[node]

        