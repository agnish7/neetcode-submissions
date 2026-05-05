class Node:
    def __init__(self):
        self.end = False
        self.right = [None] * 26

class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        curr = self.root

        for c in word:
            if not curr.right[ord(c) - ord('a')]:
                curr.right[ord(c) - ord('a')] = Node()
            curr = curr.right[ord(c) - ord('a')]

        curr.end = True

    def search_helper(self, curr, word, i):
        if curr == None:
            return False

        if i == len(word):
            return curr.end

        res = False
        if word[i] == '.':
            for j in range(26):
                res = res or self.search_helper(curr.right[j], word, i + 1)

            return res
        else:
            curr = curr.right[ord(word[i]) - ord('a')]
            return self.search_helper(curr, word, i + 1)

    def search(self, word: str) -> bool:
        if len(word) == 0:
            return True

        return self.search_helper(self.root, word, 0)

        
