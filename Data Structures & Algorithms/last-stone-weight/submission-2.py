class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-stone for stone in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            x = -heapq.heappop(stones)
            y = -heapq.heappop(stones)

            if x > y or y > x:
                heapq.heappush(stones, -abs(x - y))
            else:
                continue

        return -stones[0] if len(stones) > 0 else 0
