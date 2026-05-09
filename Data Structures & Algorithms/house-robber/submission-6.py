class Solution:
    def rob(self, nums: List[int]) -> int:
        # f(n) = max(num[n] + f(n - 2), f(n - 1))
        n = len(nums)
        f0 = nums[0]
        if n == 1:
            return f0
        f1 = max(nums[0], nums[1])
        if n == 2:
            return f1

        for i in range(2, n):
            fn = max(nums[i] + f0, f1)
            f0 = f1
            f1 = fn

        return fn