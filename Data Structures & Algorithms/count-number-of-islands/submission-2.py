class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        count = 0
        def dfs(r, c):
            nonlocal count
            if visited[r][c]:
                return

            visited[r][c] = True

            dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]

            for dir in dirs:
                x, y = r + dir[0], c + dir[1]
                if x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == '1':
                    dfs(x, y)
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] == '1' and not visited[r][c]:
                    dfs(r, c)
                    count += 1

        return count