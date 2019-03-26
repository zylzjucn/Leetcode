class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length() > t.length())
            swap(s, t);
        int i = 0;
        while (s[i] == t[i] && i < s.length())
            i++;
        if (s.length() == t.length()) {
            if (i == s.length())
                return false;
            if (s.substr(i + 1) == t.substr(i + 1))
                return true;
        }
        if (s.length() == t.length() - 1) {
            if (s.substr(i) == t.substr(i + 1))
                return true;
        }
        return false;
    }
};
