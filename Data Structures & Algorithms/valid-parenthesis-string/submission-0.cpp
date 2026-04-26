class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;
        for(auto& c: s) {
            if(c == '(') {
                ++leftMin; ++leftMax;
            } else if(c == '*') {
                --leftMin; ++leftMax;
            } else if(c == ')') {
                --leftMin; --leftMax;
            }
            if(leftMin < 0) {
                leftMin = 0;
            }
            if(leftMax < 0) {
                return false;
            }
        }
        return leftMin == 0 || leftMax == 0;
    }
};
