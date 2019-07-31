class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, sum = 0;
        map<int, int> m;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                sum++;
                if (m.find(sum) == m.end() || m[sum] == -1)
                    m[sum] = i;
            }
            else {
                if (m.find(sum) != m.end()) {
                    res = max(res, i - m[sum] + 1);
                    if (i < s.length() - 1 && s[i + 1] == ')')
                        m[sum] = -1;
                }
                sum--;
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> v(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' && i > 0 && i - v[i - 1] - 1 >= 0 && s[i - v[i - 1] - 1] == '(')
                v[i] = v[i - 1] + 2;
            if (i - v[i] >= 0)
                v[i] += v[i - v[i]];
            res = max(res, v[i]);
        }
        return res;
    }
};
