class Solution:
    def partition(self, s: str) -> List[List[str]]:
        
        def dfs(l, r):

            if l > r:
                return [[]]
            
            intermediate_res = []

            for i in range(l, r + 1):

                substring = s[l : i + 1]

                if substring == substring[::-1]:
                    for rest in dfs(i + 1, r):
                        intermediate_res.append([substring] + rest)
                        
            return intermediate_res

        return dfs(0, len(s) - 1)