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
        int n = s.length();
        // Build trie
        for(auto& word: wordDict) {
            addWord(word);
        }
        
        // dp[i] means if s[0:i] can be segmented into words
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Empty string is always valid
        
        // For each position in string
        for(int i = 0; i < n; i++) {
            // Only proceed if we can form a valid word sequence up to i
            if(!dp[i]) continue;
            
            // Try to match words starting at position i using trie
            Node* curr = &root;
            for(int j = i; j < n; j++) {
                // If no path exists in trie, break
                if(!curr->next[s[j] - 'a']) break;
                
                curr = curr->next[s[j] - 'a'];
                // If we found a word, mark dp[j+1] as true
                if(curr->end) {
                    dp[j + 1] = true;
                }
            }
        }
        
        return dp[n];
    }
};
