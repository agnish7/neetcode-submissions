class Solution {
public:
    bool isAnagram(string s, string t) {
        int cache[26] = {0};
        for(auto& c: s) {
            ++cache[c - 'a'];
        }
        for(auto& c: t) {
            --cache[c - 'a'];
            if(cache[c - 'a'] < 0) return false;
        }

        for(auto& c: cache) {
            if(c > 0) return false;
        }

        return true;
    }
};
