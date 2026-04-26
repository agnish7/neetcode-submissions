class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""

        matches = 0
        scount, tcount = defaultdict(int), defaultdict(int)

        for c in t:
            tcount[c] += 1

        needed = len(tcount)
        l = 0
        min_window = float('inf')
        min_l, min_r =  -1, -1

        for r in range(len(s)):
            c = s[r]
            scount[c] += 1
            if scount[c] == tcount[c]:
                matches += 1

            if matches == needed:
                while matches == needed:
                    c = s[l]
                    scount[c] -= 1
                    if scount[c] == tcount[c] - 1:
                        matches -= 1
                    l += 1

                if r - (l - 1) + 1 < min_window:
                    min_window = r - (l - 1) + 1
                    min_r = r
                    min_l = l - 1
            
        
        return "" if min_window == float('inf') else s[min_l: min_r + 1]