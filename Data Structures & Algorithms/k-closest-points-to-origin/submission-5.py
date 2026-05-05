class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # (distance, idx)

        points_heap = []

        for i in range(len(points)):
            x1 = points[i][0]
            y1 = points[i][1]
            dist = math.sqrt(x1 * x1 + y1 * y1)
            heapq.heappush(points_heap, (dist, i))

        res = []

        while k:
            dist, idx = heapq.heappop(points_heap)
            res.append(points[idx])
            k -= 1

        return res