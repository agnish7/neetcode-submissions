class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        key_count = defaultdict(int)
        l = 0
        max_freq = 0
        max_window = 1

        for r in range(len(s)):
            key_count[s[r]] += 1
            max_freq = max(max_freq, key_count[s[r]])
            while r - l + 1 - max_freq > k:
                key_count[s[l]] -= 1
                l += 1
            max_window = max(max_window, r - l + 1)

        return max_window                        
