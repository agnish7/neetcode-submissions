class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        stack = []
        n = len(candidates)

        def dfs(target, i):
            if target == 0:
                res.append(stack.copy())
                return
            elif i == n or target < 0:
                return
            else:
                stack.append(candidates[i])
                dfs(target - candidates[i], i + 1)
                stack.pop()

                # no inclusion
                j = 1
                while i + j < n and candidates[i + j] == candidates[i]:
                    j += 1
                dfs(target, i + j)
            
        dfs(target, 0)

        return res