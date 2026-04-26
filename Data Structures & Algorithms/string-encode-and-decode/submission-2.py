class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res = res + '#' + str(len(s)) + '#' + s
        return res
    def decode(self, s: str) -> List[str]:
        i = 0
        res = []
        while(i < len(s)): # #10##snlksdoer#4#aaaa
            if s[i] == '#':
                idx = s[i + 1:].find('#')
                print(idx)
                num = int(s[i + 1: i + idx + 1])
                res.append(s[i + idx + 2: i + idx + 2 + num])
                i = i + idx + 2 + num
            else:
                i = i + 1
        return res