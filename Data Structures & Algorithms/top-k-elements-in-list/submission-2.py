class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # k most frequent elements in the array
        freq_to_num = defaultdict(list)
        num_to_freq = [0] * 2001
        for num in nums:
            num_to_freq[num + 1000] += 1

        for i in range(len(num_to_freq)):
            freq = num_to_freq[i]
            num = i - 1000
            if(freq != 0):
                freq_to_num[freq].append(num)

        res = []

        for key, value in sorted(freq_to_num.items(), key = lambda x: -x[0]):
            if(k == 0):
                return res
            res.extend(freq_to_num[key])
            k -= len(freq_to_num[key])
        
        return res