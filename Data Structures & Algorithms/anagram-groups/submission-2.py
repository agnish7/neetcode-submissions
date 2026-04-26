class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def gen_key(s: str) -> str:
            key = [0] * 26
            for c in s:
                key[ord(c) - ord('a')] += 1
            return ".".join([str(i) for i in key])

        word_map = defaultdict(list)
        for word in strs:
            word_map[gen_key(word)].append(word)
        res = []
        for k, v in word_map.items():
            res.append(v)
        return res