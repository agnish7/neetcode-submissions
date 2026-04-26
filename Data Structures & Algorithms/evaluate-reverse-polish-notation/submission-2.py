class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = deque()
        for c in tokens:
            if c not in "+-*/":
                stack.append(c)

            elif c in "+-*/":
                print(stack)
                b = int(stack[-1])
                stack.pop()
                a = int(stack[-1])
                stack.pop()
                res = 0
                if c == '+':
                    res = a + b
                elif c == '-':
                    res = a - b
                elif c == '*':
                    res = a * b
                else:
                    res = a / b
                stack.append(res)
            
        return int(stack[-1]) if stack else 0