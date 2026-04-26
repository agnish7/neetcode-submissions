class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        j = 0
        key_count = defaultdict(int)
        for i in range(len(s)):
            key_count[s[i]] += 1
            while key_count[s[i]] > 1:
                print(j)
                key_count[s[j]] -= 1
                j += 1
            res = max(res, i - j + 1)
        return res
