class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        candidates = set(nums)
        stack = []
        n = len(nums)
        res = []

        def dfs():
            if len(stack) == n:
                res.append(stack.copy())
                return
            else:
                for candidate in list(candidates):
                    stack.append(candidate)
                    candidates.remove(candidate)
                    dfs()
                    candidates.add(candidate)
                    stack.pop()
        
        dfs()

        return res

                
