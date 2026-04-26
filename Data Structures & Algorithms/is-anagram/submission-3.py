class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        cmp_map = [0] * 26
        for c in s:
            cmp_map[ord(c) - ord('a')] += 1

        for c in t:
            cmp_map[ord(c) - ord('a')] -= 1

        for i in range(26):
            if(cmp_map[i] != 0):
                return False
        return True