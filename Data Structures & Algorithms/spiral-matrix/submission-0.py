class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        m, n = len(matrix), len(matrix[0])
        u, d, l, r = 0, m - 1, 0, n - 1

        res = []

        while u <= d and l <= r:

            for i in range(l, r + 1):
                res.append(matrix[u][i])

            u += 1

            for i in range(u, d + 1):
                res.append(matrix[i][r])

            r -= 1

            if u > d or l > r:
                break

            for i in range(r, l - 1, -1):
                res.append(matrix[d][i])

            d -= 1

            for i in range(d, u - 1, -1):
                res.append(matrix[i][l])

            l += 1

        return res