class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        A, B = s1, s2
        acount, bcount = defaultdict(int), defaultdict(int)
        l = 0

        matches, prev_matches = 0, 0

        for c in A:
            acount[c] += 1                                

        needed = len(acount.keys())
        print(needed)

        for r in range(len(B)):                             
            prev_matches = matches
            bcount[B[r]] += 1
            if bcount[B[r]] == acount[B[r]]:
                matches += 1
            elif bcount[B[r]] == acount[B[r]] + 1:
                matches -= 1

            print (r)                  
            while matches < prev_matches and l <= r:
                bcount[B[l]] -= 1
                if bcount[B[l]] == acount[B[l]]:
                    matches += 1
                elif bcount[B[l]] == acount[B[l]] - 1:
                    matches -= 1
                l += 1
            
            print(l)
            print(matches)
            if matches == needed:
                return True

            print()
        return False
