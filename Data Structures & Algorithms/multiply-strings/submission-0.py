class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        x = num1[::-1]
        y = num2[::-1]

        res = 0

        for i in range(len(x)):
            for j in range(len(y)):
                res += int(x[i]) * pow(10, i) * int(y[j]) * pow(10, j)

        return str(res)
