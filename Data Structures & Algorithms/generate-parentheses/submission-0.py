class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        res = []
        stack = []

        def dfs(opn, cls):
            
            if opn == n and cls == n:
                res.append("".join(stack))
            elif opn > n:
                return
            else:
                if cls > opn:
                    return
                elif cls == opn:
                    stack.append('(')
                    dfs(opn + 1, cls)
                    stack.pop()
                    return
                else: # cls < opn
                    stack.append('(') # add opn bracket
                    dfs(opn + 1, cls)
                    stack.pop()
                    
                    stack.append(')') # add cls bracket
                    dfs(opn, cls + 1)
                    stack.pop()

        dfs(0, 0)

        return res
