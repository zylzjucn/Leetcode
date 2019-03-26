class Solution {
public:
    bool wordPattern(string p, string str) {
        map<char, string> m1;
        map<string, char> m2;
        int start = 0;
        int end = 0;
        for (int i = 0; i < p.length(); i++) {
            if (start > str.length())
                return false;
            for (end = start; end < str.length() && str[end] != ' '; end++);
            string s = str.substr(start, end - start);
            if (m1.find(p[i]) == m1.end() && m2.find(s) == m2.end()) {
                m1[p[i]] = s;
                m2[s] = p[i];
            }
            else if (m1[p[i]] != s || m2[s] != p[i])
                return false;
            start = end + 1;
        }
        if (start < str.size())
            return false;
        return true;
    }
};
