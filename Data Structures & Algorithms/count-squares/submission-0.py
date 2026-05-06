class CountSquares:

    def __init__(self):
        self.point_map = defaultdict(int)

    def add(self, point: List[int]) -> None:
        self.point_map[(point[0], point[1])] += 1

    def count(self, point: List[int]) -> int:
        x, y = point[0], point[1]

        res = 0

        for r, c in self.point_map.keys():
            if abs(r - x) == abs(c - y) and r != x and c != y:
                squares = (
                    self.point_map.get((r, c), 0) *
                    self.point_map.get((x, c), 0) *
                    self.point_map.get((r, y), 0)
                )
                res += squares

        return res