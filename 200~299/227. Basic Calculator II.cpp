class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int i = 0;
        int pre = 0;
        char op = '+';
        while (i < s.length()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                op = s[i++];
                continue;
            }
            int j = i;
            for (; s[j] >= '0' && s[j] <= '9'; j++);
            int cur = stoi(s.substr(i, j - i));
            i = j;
            if (op == '+') {
                res += cur;
                pre = cur;
            }
            else if (op == '-') {
                res -= cur;
                pre = -cur;
            }
            else if (op == '*') {
                res = res - pre + pre * cur;
                pre *= cur;
            }
            else {
                res = res - pre + pre / cur;
                pre /= cur;
            }
        }
        return res;
    }
};
