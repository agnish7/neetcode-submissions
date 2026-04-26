class Solution {
public:
    long long binomialCoefficient(int m, int n) {
        if (m < 0 || n < 0) return 0;
        if (m > n) swap(m, n);

        long long result = 1;
        for (int i = 1; i <= m; ++i) {
            result = result * (n + i) / i;
        }
        return result;
    }
    int uniquePaths(int m, int n) {
        return binomialCoefficient(m - 1, n - 1);
    }
};
