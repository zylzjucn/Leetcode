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
