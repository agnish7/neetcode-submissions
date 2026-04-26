class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        map_s = [0] * 26
        for i in range(len(s)):
            map_s[ord(s[i]) - ord('a')] += 1

        for i in range(len(t)):
            map_s[ord(t[i]) - ord('a')] -= 1

        return not any(map_s)
