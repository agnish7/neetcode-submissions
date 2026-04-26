class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        while l <= r:
            k = (l + r) // 2
            hours = sum([math.ceil(pile/k) for pile in piles])
            print(k, hours)
            if hours > h:
                l = k + 1
            else: # hours <= h
                r = k - 1

        return l
        