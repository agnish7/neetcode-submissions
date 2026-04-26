class PrefixTree {
    struct Node {
        bool isWord;
        Node* next[26];

        Node() {
            for(int i = 0; i < 26; ++i) {
                this->next[i] = nullptr;
            }
        }
    };
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = this->root;
        for(auto& c: word) {
            if(!curr->next[c - 'a']) {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto& c: word) {
            if(curr->next[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }

        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(auto& c: prefix) {
            if(curr->next[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }

        return true;
    }
};
