class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
        int maxL = 0;
        int maxR = 0;
        // odd length palindromes
        for(int i = 0; i < s.size(); ++i) {
            int l = i, r = i;
            while(l > -1 && r < s.size() && s[l] == s[r]) {
                int len = (r - l + 1);
                if(len > maxLen) {
                    maxR = r;
                    maxL = l;
                    maxLen = len;
                }
                l--;
                r++;
            }
        }

        // even lenght palndromes
        for(int i = 0; i < s.size() - 1; ++i) {
            int l = i, r = i + 1;
            while(l > -1 && r < s.size() && s[l] == s[r]) {
                int len = (r - l + 1);
                if(len > maxLen) {
                    maxR = r;
                    maxL = l;
                    maxLen = len;
                }
                l--;
                r++;
            }
        }

        return s.substr(maxL, maxR - maxL + 1);
    }
};
