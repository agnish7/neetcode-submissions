class Solution:
    def hammingWeight(self, n: int) -> int:
        bits = 0
        while(n):
            bits += n % 2
            n = n //2

        return bits