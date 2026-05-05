class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        cols = set()
        posDiag = set()
        negDiag = set()

        stack = []
        res = []

        def backtrack(r):

            if r == n:
                res.append(stack.copy())
                return

            for c in range(n):

                if c in cols or (r + c) in posDiag or (r- c + n) in negDiag:
                    continue

                cols.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c + n)

                row = ['.'] * n
                row[c] = 'Q'
                stack.append("".join(row))

                backtrack(r + 1)

                cols.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c + n)
                
                stack.pop()

        backtrack(0)

        return res
        


            
