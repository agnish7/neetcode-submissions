class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numset = set(nums)
        res = 0
        for num in nums:
            if(num + 1 not in nums):
                seq = 0
                i = 0
                while(num - i in nums):
                    seq += 1
                    i += 1
                res = max(res, seq)
        
        return res