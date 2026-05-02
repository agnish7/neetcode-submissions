class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        stack = []
        n = len(nums)
        res = []

        def dfs(i):
            if i == n:
                res.append(stack.copy())
                return
            else:
                stack.append(nums[i])
                dfs(i + 1)
                stack.pop()

                # not included
                j = 0
                while i + j < n and nums[i + j] == nums[i]:
                    j += 1
                dfs(i + j)
                return

        dfs(0)

        return res