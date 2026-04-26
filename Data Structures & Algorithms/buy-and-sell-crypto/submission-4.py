class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            lowest = min(lowest, prices[i])
            max_profit = max(max_profit, prices[i] - lowest)
        return max_profit
        