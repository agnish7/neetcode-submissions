class Solution:
    def climbStairs(self, n: int) -> int:
        # f(n) = f(n - 1) + f(n - 2)

        f0 = 0
        f1 = 1

        for _ in range(n):
            fn = f0 + f1
            f0 = f1
            f1 = fn

        return fn