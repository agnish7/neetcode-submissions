class WordDictionary {
    struct Node {
        bool isWord;
        Node* next[26];
        Node () {
            isWord = false;
            for(int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
    };
    Node* root;
public:
    WordDictionary() {
        this->root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(auto& c: word) {
            if(!curr->next[c - 'a']) {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return searchWord(word, this->root);
    }
    bool searchWord(string word, Node* curr) {
        if(!curr) {
            return false;
        }
        for(int i = 0; i < word.size(); ++i) {
            if(word[i] == '.') {
                bool res = false;
                for(auto& p: curr->next) {

                    res = res || searchWord(word.substr(i + 1, (word.size() - 1) - (i + 1) + 1), p);
                }
                return res;
            }
            if(!curr->next[word[i] - 'a']) {
                return false;
            }
            curr = curr->next[word[i] - 'a'];
        }

        return curr->isWord;
    }
};
