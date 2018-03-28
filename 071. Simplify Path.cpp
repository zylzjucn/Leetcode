class Solution {
public:
    string simplifyPath(string s) {
        int i = s.length() - 1, j, count = 0;
        while (i >= 0) {
            if (s[i] == '/') {
                s.erase(i--, 1);
                continue;
            }
            for (j = i; s[j] != '/'; j--);
            if (j == i -1 && s[i] == '.')
                s.erase(j, 2);
            else if (j == i - 2 && s[i] == '.' && s[i - 1] == '.') {
                count++;
                s.erase(j, 3);
            }
            else if (count > 0) {
                count--;
                s.erase(j, i - j + 1);
            }
            i = j - 1;
        }
        if (s.length() == 0)
            s.push_back('/');
        return s;
    }
};
