class Node:
    def __init__(self):
        self.end = False
        self.right = [None] * 26

class Solution:
    def __init__(self):
        self.root = Node()

    def add_word(self, word):
        curr = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if not curr.right[idx]:
                curr.right[idx] = Node()
            curr = curr.right[idx]
        
        curr.end = True

    def search_word(self, stack, res, curr, board, visited, r, c):
        if r >= len(board) or c >= len(board[0]) or r < 0 or c < 0:
            return

        if visited[r][c]:
            return

        idx = ord(board[r][c]) - ord('a')

        if not curr.right[idx]:
            return

        curr = curr.right[idx]

        visited[r][c] = True
        stack.append(board[r][c])

        if curr.end:
            res.append("".join(stack))
            curr.end = False  # avoids duplicate words

        self.search_word(stack, res, curr, board, visited, r + 1, c)
        self.search_word(stack, res, curr, board, visited, r - 1, c)
        self.search_word(stack, res, curr, board, visited, r, c + 1)
        self.search_word(stack, res, curr, board, visited, r, c - 1)

        stack.pop()
        visited[r][c] = False

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        for word in words:
            self.add_word(word)

        visited = [[False] * len(board[0]) for _ in range(len(board))]

        res = []
        stack = []

        for r in range(len(board)):
            for c in range(len(board[0])):
                self.search_word(stack, res, self.root, board, visited, r, c)

        return res