class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = self.nxt = None
class LRUCache:
    
    def __init__(self, capacity: int):
        self.cache = {}
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.cap = capacity

        self.head.nxt = self.tail
        self.tail.prev = self.head

    def remove(self, node):                                                                       
        former, latter = node.prev, node.nxt
        former.nxt = latter
        latter.prev = former
        node.nxt, node.prev = None, None

    def insert(self, node):
        former = self.tail.prev
        latter = self.tail

        former.nxt = node
        node.prev = former

        latter.prev = node
        node.nxt = latter                               

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        self.remove(self.cache[key])
        self.insert(self.cache[key])
        return self.cache[key].val
        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            lru = self.head.nxt
            self.remove(lru)
            del self.cache[lru.key]