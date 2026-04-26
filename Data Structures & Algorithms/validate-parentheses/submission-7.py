class Solution:
    def isValid(self, s: str) -> bool:
        stack = deque()

        for c in s:
            if c in "({[":
                stack.append(c)
                continue
            elif not stack:
                return False
            elif stack[-1] == '(' and c != ')' or \
            stack[-1] == '{' and c != '}' or \
            stack[-1] == '[' and c != ']':
                return False
            stack.pop()
            
        return not stack