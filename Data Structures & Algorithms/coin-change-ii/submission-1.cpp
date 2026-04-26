class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unordered_map<string, int> cache;
        return recur(amount, 0, coins, cache);
    }
    int recur(int amount, int i, vector<int>& coins, unordered_map<string, int>& cache) {
        if(cache.count(to_string(amount) + "#" + to_string(i))) {
            return cache[to_string(amount) + "#" + to_string(i)];
        }
        if(amount == 0) {
            cache[to_string(amount) + "#" + to_string(i)] = 1;
            return 1;
        }
        if(amount < 0 || i == coins.size()) {
            cache[to_string(amount) + "#" + to_string(i)] = 0;
            return 0;
        }
        int res = recur(amount - coins[i], i, coins, cache) + recur(amount, i + 1, coins, cache);
        cache[to_string(amount) + "#" + to_string(i)] = res;
        return res;
    }
};
