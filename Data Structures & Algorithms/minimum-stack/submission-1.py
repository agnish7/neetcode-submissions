class MinStack:

    def __init__(self):
        self.stack = deque()
        self.minstack = deque()

    def push(self, val: int) -> None:
        self.stack.append(val)
        self.minstack.append(val if not self.minstack else min(val, self.getMin()))

    def pop(self) -> None:
        self.stack.pop()
        self.minstack.pop()

    def top(self) -> int:
        if self.stack:
            return self.stack[-1]

    def getMin(self) -> int:
        if self.minstack:
            return self.minstack[-1]
