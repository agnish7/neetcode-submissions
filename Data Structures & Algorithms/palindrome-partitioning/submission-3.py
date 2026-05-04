class Solution:
    def __init__(self):
        self.res = []
        self.stack = []

    def is_palindrome(self, s):
        return s == s[::-1]

    def backtrack(self, s, start):
        if start == len(s):
            self.res.append(self.stack[:])
            return

        for i in range(start, len(s)):
            palindrome = s[start:i + 1]

            if self.is_palindrome(palindrome):
                self.stack.append(palindrome)
                self.backtrack(s, i + 1)
                self.stack.pop()
    
    def partition(self, s: str) -> List[List[str]]:
        self.backtrack(s, 0)
        return self.res