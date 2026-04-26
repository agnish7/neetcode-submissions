class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        bool flag = false;
        while(l <= r) {
            if(s[l] == s[r]) {
                ++l;
                --r;
            } else if(s[l] == s[r-1]) {
                if(flag) return false;
                flag = true;
                --r;
            } else if(s[l + 1] == s[r]) {
                if(flag) return false;
                flag = true;
                ++l;
            } else {
                return false;
            }
        }
        return true;

    }
};