class Solution {
    vector<vector<int>> cache;
public:
    bool isMatch(string s, string p) {
        cache.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return backtrack(s, p, 0, 0);
    }
    bool backtrack(string& s, string& t, int i, int j) {
        if(i >= s.size() && j == t.size()) {
            return true;
        }
        if(j >= t.size()) {
            return false;
        }
        if(cache[i][j] != -1) {
            return cache[i][j];
        }

        bool res = false;

        bool match = (i < s.size() && (s[i] == t[j] || t[j] == '.'));

        if(j + 1 < t.size() && t[j + 1] == '*') {
            res = (match && backtrack(s, t, i + 1, j)) ||  backtrack(s, t, i, j + 2);
        } else if (match) {
            res = backtrack(s, t, i + 1, j + 1);
        } else {
            res = false;
        }
        cache[i][j] = res;
        return res;
    }
};
