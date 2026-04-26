class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesis_stack{};
        unordered_set<char> opening_brackets{'(', '{', '['};
        for(int i = 0; i < s.size(); ++i) {
            if(opening_brackets.find(s[i]) != opening_brackets.end()) {
                cout << "found openning bracket: " << s[i] << endl;
                parenthesis_stack.push(s[i]);
            } else {
                // print out stack
                // stack<char> temp(parenthesis_stack);
                // cout << "temp: ";
                // while(!temp.empty()) {
                //     cout << temp.top() << " ";
                //     temp.pop();
                // }
                // cout << endl;
                // cout << "s[i]: " << s[i];
                //////////////////
                if(s[i] == ')' && (parenthesis_stack.empty() or parenthesis_stack.top() != '(') ||
                    s[i] == '}' && (parenthesis_stack.empty() or parenthesis_stack.top() != '{') ||
                    s[i] == ']' && (parenthesis_stack.empty() or parenthesis_stack.top() != '[')) {
                        return false;
                } else {
                    if(!parenthesis_stack.empty())
                        parenthesis_stack.pop();
                }
            }
        }
        return parenthesis_stack.empty();
    }
};
