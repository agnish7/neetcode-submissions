class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = 0
        count = 0
        visited = [[False]*n for _ in range(m)]

        def dfs(r, c):
            nonlocal count
            if visited[r][c]:
                return

            visited[r][c] = True

            dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]

            for dir in dirs:
                x, y = r + dir[0], c + dir[1]
                if x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1:
                    dfs(x, y)

            count += 1

        for r in range(m):
            for c in range(n):
                count = 0
                if grid[r][c] == 1:
                    dfs(r, c)
                res = max(res, count)

        return res
            