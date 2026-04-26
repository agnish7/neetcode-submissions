class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> LCS(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i = text1.size() - 1; i > -1; --i) {
            for(int j = text2.size() - 1; j > -1; --j) {
                if(text1[i] == text2[j]) {
                    LCS[i][j] = 1 + LCS[i + 1][j + 1];
                } else {
                    LCS[i][j] = max(LCS[i][j + 1], LCS[i + 1][j]);
                }
            }
        }
        return LCS[0][0];
    }
};
