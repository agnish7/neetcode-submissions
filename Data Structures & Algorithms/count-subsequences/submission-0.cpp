class Solution {
public:
    int numDistinct(string s, string t) {
        return backtrack(0, "", s, t);
    }
    int backtrack(int i, string curr, string& s, string& t) {
        cout << i << " " << curr << endl;
        if(i == s.size())
            return curr == t;
        if(curr[curr.size() - 1] != t[curr.size() - 1]) {
            return 0;
        }
        if(curr.size() > t.size()) {
            return 0;
        }
        return backtrack(i + 1, curr + s[i], s, t) + backtrack(i + 1, curr, s, t);
    }
};
