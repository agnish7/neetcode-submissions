class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        A, B = s1, s2
        acount, bcount = defaultdict(int), defaultdict(int)

        for c in A:
            acount[c] += 1

        needed = len(acount)
        matches = 0
        l = 0

        for r in range(len(B)):
            # expand
            c = B[r]
            bcount[c] += 1

            if bcount[c] == acount[c]:
                matches += 1
            elif bcount[c] == acount[c] + 1:
                matches -= 1

            # enforce window size constraint
            while (r - l + 1) > len(A):
                left = B[l]
                bcount[left] -= 1

                if bcount[left] == acount[left]:
                    matches += 1
                elif bcount[left] == acount[left] - 1:
                    matches -= 1

                l += 1

            # check valid window
            if matches == needed:
                return True

        return False