class Solution {
public:
    string parseTernary(string str) {
        stack<char> s;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] != ':' && str[i] != '?')
                s.push(str[i]);
            else if (str[i] == '?') {
                i--;
                char c;
                if (str[i] == 'T') {
                    c = s.top();
                    s.pop();
                }
                else {
                    s.pop();
                    c = s.top();
                }
                s.pop();
                s.push(c);
            }
        }
        string res(1, s.top());
        return res;
    }
};
