class Solution {
public:
    bool isStrobogrammatic(string s) {
        int i = 0, j = s.length() - 1;
        for (; i < j; i++, j--) {
            if ((s[i] == s[j] && (s[i] == '0' || s[i] == '1' || s[i] == '8')) || (s[i] == '6' && s[j] == '9') || (s[i] == '9' && s[j] == '6'))
                continue;
            return false;
        }
        if (i == j)
            return s[i] == '0' || s[i] == '1' || s[i] == '8';
        return true;
    }
};
