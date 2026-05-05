class Solution:
    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        seen = set()

        while True:
            seen.add(n)
            digits = []
            num = n
            seen.add(num)
            while num:
                digits.append(num % 10)
                num = num // 10

            digits2 = [x * x for x in digits]
            n = sum(digits2)
            if n in seen:
                return False
            
            if n == 1:
                return True
            