class Solution {
public:
    int minDistance(string word1, string word2) {
        return backtrack(word1, word2, 0, 0);
    }
    int backtrack(string& s, string&t, int i, int j) {
        if(j == t.size()) {
            return s.size() - i;
        }
        if(i == s.size()) {
            return t.size() - j;
        }
        if(s[i] == t[j]) {
            return backtrack(s, t, i + 1, j + 1);
        }
        int add = 1 + backtrack(s, t, i, j + 1);
        int del = 1 + backtrack(s, t, i + 1, j);
        int rep = 1 + backtrack(s, t, i + 1, j + 1);
        return min(add, min(del, rep));
    }
};
