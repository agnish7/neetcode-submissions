class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // Initialize graph and in-degree map
        unordered_map<char, unordered_set<char>> adj; // Adjacency list
        unordered_map<char, int> inDeg;               // Tracks in-degrees and characters

        for (const string& word : words) {
            for (char c : word) {
                inDeg[c] = 0;
            }
        }

        // Build graph by comparing adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            const string& w1 = words[i];
            for(char c: w1) {

            }
            const string& w2 = words[i + 1];
            // Check for invalid case (e.g., "abc" > "ab")
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }
            // Find first differing characters
            for (int j = 0; j < min(w1.size(), w2.size()); ++j) {
                if (w1[j] != w2[j]) {
                    // Initialize inDeg for both characters if not present
                    if (!inDeg.count(w1[j])) inDeg[w1[j]] = 0;
                    if (!inDeg.count(w2[j])) inDeg[w2[j]] = 0;
                    // Add edge if not already present
                    if (adj[w1[j]].insert(w2[j]).second) {
                        inDeg[w2[j]]++;
                    }
                    break; // Only need first differing pair
                }
            }
        }

        // Initialize BFS with nodes having in-degree 0
        queue<char> q;
        for (const auto& p : inDeg) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        // Run BFS
        string res;
        while (!q.empty()) {
            char letter = q.front();
            res += letter;
            q.pop();
            for (const auto& nextLetter : adj[letter]) {
                inDeg[nextLetter]--;
                if (inDeg[nextLetter] == 0) {
                    q.push(nextLetter);
                }
            }
        }

        // Validate result (check for cycle)
        return res.length() == inDeg.size() ? res : "";
    }
};