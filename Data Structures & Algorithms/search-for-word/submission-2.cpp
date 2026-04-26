class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                res = res || backtrack(i, j, 0, {}, board, word);
            }
        }
        return res;
    }
    bool backtrack(int r, int c, int i, unordered_set<string> seen, vector<vector<char>>& board, string& word) {
        if(r >= board.size() || r < 0 || c >= board[0].size() || c < 0) {
            return false;
        }
        if(board[r][c] != word[i] || seen.count(to_string(r) + to_string(c))) {
            return false;
        }
        if(i == word.size() - 1) {
            return board[r][c] == word[word.size() - 1];
        }

        seen.insert(to_string(r) + to_string(c));
        return
        backtrack(r + 1, c, i + 1, seen, board, word) ||
        backtrack(r - 1, c, i + 1, seen, board, word) ||
        backtrack(r, c - 1, i + 1, seen, board, word) ||
        backtrack(r, c + 1, i + 1, seen, board, word);
    }
};
