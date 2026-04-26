class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        backtrack(0, s.size() - 1, {}, s, res);
        return res;
    }
    bool checkPalindrome(int i, int j, string& s) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(int i, int j, vector<string> currPartition, string& s, vector<vector<string>>& res) {
        if(i == s.size())  {
            res.push_back(currPartition);
            return;
        }
        for(int idx = i; idx <= j; ++idx) {
            if(checkPalindrome(i, idx, s)) {
                currPartition.push_back(s.substr(i, idx - i + 1));
                backtrack(idx + 1, j, currPartition, s, res);
                currPartition.pop_back();
            }
        }
    }
};
