class Solution {
    unordered_map<int, int> cache;
public:
    int numDecodings(string s) {
        return numWays(s, 0);
    }
    int numWays(string& s, int l) {
        if(cache.count(l)) {
            return cache[l];
        }

        if(s.size() - l == 0) {
            return 1;
        }
        if(s[l] == '0') {
            return 0;
        }
        int res = -1;
        if(s[l] == '1') {
            res = numWays(s, l + 1) + numWays(s, l + 2);
            cache[l] = res;
            return res;
        }
        if(s[l] == '2') {
            if(s[l + 1] - '0' > 6) {
                res = numWays(s, l + 1);
                cache[l] = res;
                return res;
            } else {
                res = numWays(s, l + 1) + numWays(s, l + 2);
                cache[l] = res;
                return res;
            }
        }
        res = numWays(s, l + 1);
        cache[l] = res;
        return res;
    }
};
