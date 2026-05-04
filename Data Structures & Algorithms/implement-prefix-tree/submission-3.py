class Node:
    def __init__(self):
        self.nxt = [None] * 26
        self.end = False
class PrefixTree:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if not curr.nxt[ord(c) - ord('a')]:
                curr.nxt[ord(c) - ord('a')] = Node()
            curr = curr.nxt[ord(c) - ord('a')]
        curr.end = True

    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if not curr.nxt[ord(c) - ord('a')]:
                return False
            curr = curr.nxt[ord(c) - ord('a')]

        return curr.end

    def startsWith(self, prefix: str) -> bool:

        curr = self.root
        for c in prefix:
            if not curr.nxt[ord(c) - ord('a')]:
                return False
            curr = curr.nxt[ord(c) - ord('a')]

        return True
        
        