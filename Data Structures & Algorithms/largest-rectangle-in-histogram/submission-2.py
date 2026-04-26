from collections import deque

class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        n = len(heights)
        stack = deque()
        max_area = 0

        left, right = [0] * n, [0] * n

        for i in range(n):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            left[i] = stack[-1] if stack else -1
            stack.append(i)

        stack.clear()

        for i in range(n - 1, -1, -1):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            right[i] = stack[-1] if stack else n
            stack.append(i)
        
        for i in range(n):
            width = right[i] - left[i] - 1
            max_area = max(max_area, heights[i] * width)

        return max_area