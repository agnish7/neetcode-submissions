class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        A, B = s1, s2

        if len(A) > len(B):
            return False

        acount, bcount = defaultdict(int), defaultdict(int)

        for c in A:
            acount[c] += 1
        
        matches, needed = 0, len(acount)
        l = 0
        for r in range(len(B)):
            c = B[r]
            bcount[c] += 1
            if bcount[c] == acount[c]:
                matches += 1
            elif bcount[c] == acount[c] + 1:
                matches -= 1

            while r - l + 1 > len(A):
                c = B[l]
                bcount[c] -= 1
                if bcount[c] == acount[c]:
                    matches += 1
                elif bcount[c] == acount[c] - 1:
                    matches -= 1
                l += 1
            
            if matches == needed:
                return True

        return False
