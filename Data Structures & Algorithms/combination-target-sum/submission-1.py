class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        stack = []
        amount = target
        n = len(nums)

        def dfs(i):
            nonlocal res
            nonlocal amount
            nonlocal n
            nonlocal stack

            if i == n:

                return
            elif amount < 0:

                return

            elif amount == 0:
                # print(stack)
                res.append(stack.copy())
                return
            else:
                amount -= nums[i]
                stack.append(nums[i])
                dfs(i)
                amount += nums[i]
                stack.pop()
                dfs(i + 1)

        dfs(0)

        return res

            