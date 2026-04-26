class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        l, r = [], [1] * len(nums)
        prod = 1
        for num in nums:
            prod = prod * num
            l.append(prod)
        
        prod = 1
        for i in range(len(nums) - 1, -1, -1):
            prod = prod * nums[i]
            r[i] = prod
        
        res = [1] * len(nums)
        for i in range(1, len(nums) - 1):
            res[i] = l[i - 1] * r[i + 1]

        res[0], res[-1] = r[1], l[-2]
        return res