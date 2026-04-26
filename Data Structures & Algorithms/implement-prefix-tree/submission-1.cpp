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

class PrefixTree {
    Node root;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
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
        Node* curr =  &this->root;
        for(auto& c: word) {
            if(!curr->next[int(c) - int('a')]) {
                return false;
            }
            curr = curr->next[int(c) - int('a')];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        Node* curr = &this->root;
        for(auto& c: prefix) {
            if(!curr->next[int(c) - int('a')]) {
                return false;
            }
            curr = curr->next[int(c) - int('a')];
        }
        return true;
    }
};
