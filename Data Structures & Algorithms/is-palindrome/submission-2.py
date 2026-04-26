class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join(c.lower() for c in s if c.isalnum())
        return s[:len(s) // 2] == s[::-1][:len(s)//2]