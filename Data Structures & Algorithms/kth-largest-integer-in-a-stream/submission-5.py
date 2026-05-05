class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.pq = nums[:k]
        heapq.heapify(self.pq)
        for num in nums[k:]:
            if num > self.pq[0]:
                heapq.heappop(self.pq)
                heapq.heappush(self.pq, num)
        
        print(self.pq)
        
    def add(self, val: int) -> int:
        heapq.heappush(self.pq, val)
        if len(self.pq) > self.k:
            heapq.heappop(self.pq)


        return self.pq[0]
