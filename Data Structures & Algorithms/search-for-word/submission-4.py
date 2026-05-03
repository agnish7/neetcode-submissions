class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        m, n = len(board), len(board[0])
        end = len(word)
        visited = [[False] * n for _ in range(m)]

        def dfs(i, r, c):
            if i == end:
                return True

            if r == -1 or c == -1 or r == m or c == n:
                return False
            
            if visited[r][c]:
                return False

            visited[r][c] = True
            
            if board[r][c] == word[i]:
                tmp = \
                dfs(i + 1, r + 1, c) or \
                dfs(i + 1, r - 1, c) or \
                dfs(i + 1, r, c + 1) or \
                dfs(i + 1, r, c - 1)
                visited[r][c] = False
                return tmp
            else:
                visited[r][c] = False
                return False
            

        res = False

        for r in range(m):
            for c in range(n):
                # print(dfs(0, r, c))
                tmp = dfs(0, r, c)
                res = res or tmp

        return res
            

