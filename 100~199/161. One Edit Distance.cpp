class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int i = 0;
        for (; i < s.length() && i < t.length(); i++) {
            if (s[i] != t[i]) {
                return s.substr(i + 1) == t.substr(i) || s.substr(i) == t.substr(i + 1) || s.substr(i + 1) == t.substr(i + 1);
            }
        }
        return (i == s.length() && i == t.length() - 1) || (i == t.length() && i == s.length() - 1);
    }
};
