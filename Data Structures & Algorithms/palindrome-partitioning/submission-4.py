class Solution:
    def __init__(self):
        self.res = []
        self.stack = []

    def is_palindrome(self, s):
        return s == s[::-1]

    def backtrack(self, s, i):
        if i == len(s):
            self.res.append(self.stack[:])
            return

        for j in range(i, len(s)):
            if self.is_palindrome(s[i:j+1]):
                self.stack.append(s[i:j+1])
                self.backtrack(s, j + 1)
                self.stack.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.backtrack(s, 0)
        return self.res