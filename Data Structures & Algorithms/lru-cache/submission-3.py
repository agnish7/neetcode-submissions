class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = self.nxt = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.cache = {}

        self.head.nxt = self.tail
        self.tail.prev = self.head

    def insert_at_tail(self, node):
        left, right = self.tail.prev, self.tail
        left.nxt, node.prev = node, left
        right.prev, node.nxt = node, right

    def remove_node(self, node):
        left, right = node.prev, node.nxt
        left.nxt, right.prev = right, left
        node.prev, node.nxt = None, None

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove_node(self.cache[key])
            self.insert_at_tail(self.cache[key])
            return self.cache[key].val
        else:
            return -1


    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove_node(self.cache[key])

        self.cache[key] = Node(key, value)
        self.insert_at_tail(self.cache[key])

        if len(self.cache) > self.cap:
            lru = self.head.nxt
            self.remove_node(lru)
            del self.cache[lru.key]
