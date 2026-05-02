class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]

        n = len(nums)

        for i in range(n):
            tmp =  res.copy()
            for t in tmp:
                res.append(t + [nums[i]])

        return res