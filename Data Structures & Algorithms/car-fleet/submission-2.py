class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        def meets(car1, car2):
            return (target - car1[0]) / car1[1] <= (target - car2[0]) / car2[1]

        cars = [(position[i], speed[i]) for i in range(len(position))]
        cars.sort()

        s = deque()

        for car in cars:
            while s and meets(s[-1], car):
                s.pop()
            s.append(car)



        return len(s)