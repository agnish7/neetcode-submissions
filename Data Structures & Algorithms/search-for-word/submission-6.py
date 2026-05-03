class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])        
        visited = [[False] * n for _ in range(m)]
        N = len(word)

        def dfs(i, r, c):
            if i == N:
                return True
            if r >= m or c >= n or r < 0 or c < 0:
                return False
            if visited[r][c] or board[r][c] != word[i]:
                return False

            visited[r][c] = True

            tmp = dfs(i + 1, r + 1, c) or \
            dfs(i + 1, r - 1, c) or \
            dfs(i + 1, r, c + 1) or \
            dfs(i + 1, r, c - 1)

            visited[r][c] = False
            return tmp
            
        res = False
        for r in range(m):
            for c in range(n):
                res = res or dfs(0, r, c)
        
        return res