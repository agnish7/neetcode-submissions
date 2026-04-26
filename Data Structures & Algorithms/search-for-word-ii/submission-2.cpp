class Solution {
    struct Node {
        bool end;
        Node* next[26];
        Node() {
            this->end = false;
            for(int i = 0; i < 26; ++i) {
                this->next[i] = nullptr;
            }
        }
    };
    Node root;
public:
    void addWord(string& word) {
        Node* curr = &this->root;
        for(auto& c: word) {
            if(!curr->next[int(c) - int('a')]) {
                curr->next[int(c) - int('a')] = new Node();
            }
            curr = curr->next[int(c) - int('a')];
        }
        curr->end = true;
    }
    void addWords(vector<string>& words) {
        for(auto& word: words) {
            addWord(word);
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        addWords(words);
        vector<string> res;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                search(res, board, i, j, "", &this->root, {});
            }
        }
        return res;
    }
    void search(vector<string>& res, vector<vector<char>>& board, int r, int c, string currWord, Node* currNode, unordered_set<string> visited) {
        // cout << r << " " << c << " " << currWord << " " << currNode->end << endl;        
        if(r >= board.size() || c >= board[0].size() || visited.count(to_string(r) + "#" + to_string(c))) {
            return;
        }

        if(!currNode->next[int(board[r][c]) - int('a')]) {
            return;
        }
        currWord += board[r][c];
        currNode = currNode->next[int(board[r][c]) - int('a')];
        if(currNode->end == true) {
            res.push_back(currWord);
            currNode->end = false;
        }
        visited.insert(to_string(r) + "#" + to_string(c));
        search(res, board, r + 1, c, currWord, currNode, visited);
        search(res, board, r, c + 1, currWord, currNode, visited);
        search(res, board, r - 1, c, currWord, currNode, visited);
        search(res, board, r, c - 1, currWord, currNode, visited);
    }
};
