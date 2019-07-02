class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        int ipre = -1;
        int jpre = -1;
        while (i < s.length()) {
            if (i < s.length() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (j < p.length() && p[j] == '*') {
                ipre = i;
                jpre = j;
                j++;
            }
            else if (ipre != -1) {
                j = jpre + 1;
                ipre++;
                i = ipre;
            }
            else
                return false;
        }
        while (j < p.length() && p[j] == '*')
            j++;
        return j == p.length();
    }
};
