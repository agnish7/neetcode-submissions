import bisect

class TimeMap:

    def __init__(self):
        self.key_store = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.key_store[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if(key in self.key_store):
            index = bisect.bisect_right(self.key_store[key], (timestamp, chr(127))) - 1

            if index<0:
                return ""
            print(index)


            return self.key_store[key][index][1]
        else:
            return ""
