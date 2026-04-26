class Solution {
    struct Node {
        bool end;
        Node* next[26];
        Node() {
            end = false;
            for(int i = 0; i < 26; ++i) {
                this->next[i] = nullptr;
            }
        }
    };
    Node root;
    unordered_map<int, bool> cache;
public:
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
    bool wordBreak(string s, vector<string>& wordDict) {
        cache.clear();
        for(auto& word: wordDict) {
            addWord(word);
        }
        return check(s, 0);
    }

    bool check(string& s, int start) {
        // If we've reached the end of the string, we're done
        if (start == s.length()) {
            return true;
        }
        
        // If we've already computed this state, return cached result
        if (cache.count(start)) {
            return cache[start];
        }
        
        // Try matching words starting from current position
        Node* curr = &root;
        for (int i = start; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (!curr->next[idx]) {
                break;  // No matching prefix exists
            }
            curr = curr->next[idx];
            if (curr->end && check(s, i + 1)) {
                // If we found a word and the rest of the string can be broken
                cache[start] = true;
                return true;
            }
        }
        
        cache[start] = false;
        return false;
    }
};
