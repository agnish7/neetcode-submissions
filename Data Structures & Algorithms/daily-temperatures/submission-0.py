class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = deque()
        res = [0] * len(temperatures)

        for i, temp in enumerate(temperatures):
            # print(stack)
            if not stack:
                stack.append(i)
                continue
            while stack and temp > temperatures[stack[-1]]:
                top_idx = stack[-1]
                res[top_idx] = i - top_idx
                stack.pop()
            stack.append(i)
        
        # while stack:
        #     top_idx = stack[-1]
        #     res[top_idx] = 0
        #     stack.pop()
        
        return res
