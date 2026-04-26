class WordDictionary {
    struct Node {
        bool end;
        Node* next[26];
        Node() {
            for(int i = 0; i < 26; ++i) {
                this->next[i] = nullptr;
            }
        }
    };
    Node root;
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        Node* curr = &this->root;
        for(auto& c: word) {
            if(!curr->next[int(c) - int('a')]) {
                curr->next[int(c) - int('a')] = new Node();
            }
            curr = curr->next[int(c) - int('a')];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return findWord(word, 0, &this->root);
    }

    bool findWord(string& word, int i, Node* curr) {
        if(i > word.size() || curr == nullptr) {
            return false;
        }
        if(i == word.size()) {
            return curr->end;
        }
        if(word[i] == '.') {
            bool res = false;
            for(int j = 0; j < 26; ++j) {
                res = res || findWord(word, i + 1, curr->next[j]);
            }
            return res;
        }
        if(!curr->next[word[i] - int('a')]) {
            return false;
        }
        return findWord(word, i + 1, curr->next[word[i] - int('a')]);
    }
};
