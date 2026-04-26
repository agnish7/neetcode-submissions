class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        unordered_map<char, string> numMap {{'2', "abc"}, 
        {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> res;
        backtrack(0, digits, "", res, numMap);
        return res;
    }
    void backtrack(int idx, string& digits, string combination, vector<string>& res, unordered_map<char, string>& numMap) {
        if(idx == digits.size()) {
            res.push_back(combination);
            return;
        }

        for(auto& c: numMap[digits[idx]]) {
            combination.push_back(c);
            backtrack(idx + 1, digits, combination, res, numMap);
            combination.pop_back();
        }
    }
};
