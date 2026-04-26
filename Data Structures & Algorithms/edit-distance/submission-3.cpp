class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> res(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int j = 0; j < word2.size(); ++j) {
            res[word1.size()][j] = word2.size() - j;
        }
        for(int i = 0; i < word1.size(); ++i) {
            res[i][word2.size()] = word1.size() - i;
        }
        for(int i = res.size() - 2; i > -1; --i) {
            for(int j = res[0].size() - 2; j > -1; --j) {
                if(word1[i] == word2[j]) {
                    res[i][j] = res[i + 1][j + 1];
                } else {
                    res[i][j] = min(res[i + 1][j + 1], min(res[i][j + 1], res[i + 1][j])) + 1;
                }
            }
        }
        return res[0][0];
    }
};
