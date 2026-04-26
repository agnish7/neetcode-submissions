class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> res(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 0; i < res.size(); ++i) {
            res[i][res[0].size() - 1] = 1;
        }
        for(int i = res.size() - 2; i > -1; --i) {
            for(int j = res[0].size() - 2; j > -1; --j) {
                if(s[i] == t[j]) {
                    res[i][j] = res[i + 1][j + 1] + res[i + 1][j];
                } else {
                    res[i][j] = res[i + 1][j];
                }
            }
        }
        return res[0][0];
    }
};
