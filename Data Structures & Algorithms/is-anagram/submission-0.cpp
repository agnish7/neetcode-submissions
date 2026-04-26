class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map{}, t_map{};
        for(int i = 0; i < s.size(); ++i) {
            if(s_map.find(s[i]) != s_map.end()) {
                s_map[s[i]]++;
            } else {
                s_map[s[i]] = 1;
            }
        }

        for(int i = 0; i < t.size(); ++i) {
            if(t_map.find(t[i]) != t_map.end()) {
                t_map[t[i]]++;
            } else {
                t_map[t[i]] = 1;
            }
        }

        if(s_map.size() != t_map.size()) {
            return false;
        } else {
            for(auto i = s_map.begin(); i != s_map.end(); ++i) {
                char s_key = i->first;
                int s_val = i->second;
                if(t_map[s_key] != s_val) {
                    return false;
                }
            }
        }
        return true;
    }
};
