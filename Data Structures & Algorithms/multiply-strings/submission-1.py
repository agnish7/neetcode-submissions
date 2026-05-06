class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        x = num1[::-1]
        y = num2[::-1]

        res = [0] * (len(x) + len(y))

        for i in range(len(x)):
            for j in range(len(y)):
                pos = i + j

                mul = int(x[i]) * int(y[j])
                mul_digit = mul % 10
                mul_carry = mul // 10

                # add digit
                total = res[pos] + mul_digit

                sum_digit = total % 10
                sum_carry = total // 10

                res[pos] = sum_digit

                # add BOTH carries
                res[pos + 1] += sum_carry + mul_carry

        # remove leading zeros
        while len(res) > 1 and res[-1] == 0:
            res.pop()

        return "".join(map(str, res[::-1]))