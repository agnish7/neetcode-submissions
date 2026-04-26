class Solution {
public:
    int climbStairs(int n) {
        int fib1 = 1, fib2 = 1, fib3 = 1;
        for(int i = 1; i < n; ++i) {
            fib3 = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib3;
        }
        return fib3;
    }
};
