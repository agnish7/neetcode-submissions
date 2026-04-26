class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string, bool> cache;
        if(s3.size() != s1.size() + s2.size()) {
            return false;
        }
        return backtrack(s1,s2,s3,0,0,"", cache);
    }
    bool backtrack(string& s1, string& s2, string& s3, int i, int j, string curr, unordered_map<string, bool> cache) {
        if(cache.count(to_string(i) + "#" + to_string(j))) {
            return cache[to_string(i) + "#" + to_string(j)];
        }
        int k = i + j;
        int res = false;
        if(curr != "" && curr[k - 1] != s3[k - 1]) {
            res = false;
        } else if(i == s1.size() && j == s2.size()) {
            res = curr == s3;
        } else if(i == s1.size()) {
            res = curr + s2.substr(j, s2.size() - j + 1) == s3;
        } else if(j == s2.size()) {
            res = curr + s1.substr(i, s1.size() - i + 1) == s3;
        } else
            res = backtrack(s1,s2,s3,i+1,j,curr+s1[i],cache) || backtrack(s1,s2,s3,i,j+1,curr+s2[j],cache);
        cache[to_string(i) + "#" + to_string(j)] = res;
        return res;
    }
};
