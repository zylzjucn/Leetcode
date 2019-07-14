class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for (const auto& c : str) {
            if (c == '(' || c == '{' || c == '[')
                s.push(c);
            else {
                if (s.empty())
                    return false;
                else if ((c == ')' && (s.top() != '(')) || (c == '}' && (s.top() != '{')) || (c == ']' && (s.top() != '[')))
                    return false;
                else
                    s.pop();
            }
        }
        return s.empty();
    }
};
