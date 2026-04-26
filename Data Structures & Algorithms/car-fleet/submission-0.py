class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        merged = [[position[i], speed[i]] for i in range(len(position))]
        merged.sort(key=lambda pos: pos[0], reverse=True)

        def is_merge(a, b):
            t_a = (target - a[0]) / a[1]
            t_b = (target - b[0]) / b[1]
            return t_b <= t_a

        stack = deque()

        for element in merged:
            if not stack:
                stack.append(element)
                continue

            if is_merge(stack[-1], element):
                continue

            stack.append(element)

        return len(stack)