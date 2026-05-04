class Solution:
    def __init__(self):
        self.num_to_letters = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        self.stack = []
        self.res = []

    def backtrack(self, digits, i):
        if i == len(digits):
            self.res.append("".join(self.stack))
            return
        
        for c in self.num_to_letters[digits[i]]:
            self.stack.append(c)
            self.backtrack(digits, i + 1)
            self.stack.pop()

    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        self.backtrack(digits, 0)
        return self.res