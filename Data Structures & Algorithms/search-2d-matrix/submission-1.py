class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        u, d = 0, len(matrix) - 1
        m, n = len(matrix), len(matrix[0])
        r, c = -1, -1
        while u <= d:
            mid = (u + d) // 2
            if matrix[mid][0] <= target <= matrix[mid][-1]:
                r = mid
                break
            elif target < matrix[mid][0]:
                d = mid - 1
            else:
                u = mid + 1
    
        if r == -1:
            return False

        left, right = 0, len(matrix[0]) - 1
        while left <= right:
            mid = (left + right) // 2
            if target == matrix[r][mid]:
                c = mid
                break
            elif target < matrix[r][mid]:
                right = mid - 1
            else:
                left = mid + 1

        return False if c == -1 else True