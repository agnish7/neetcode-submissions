from collections import defaultdict
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = defaultdict()
        for i in range(len(nums)):
            if(nums[i] in num_map):
                return [num_map[nums[i]], i]
            num_map[target - nums[i]] = i
        
        return [-1, -1]