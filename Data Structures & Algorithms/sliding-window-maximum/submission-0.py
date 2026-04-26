class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        res = []
        l = 0
        for i in range(len(nums)):
            while q and nums[q[-1]] < nums[i]:
                q.pop()

            q.append(i)

            if q[0] < l:
                q.popleft()

            if(i + 1) >= k:
                res.append(nums[q[0]])
                l += 1

        return res