class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        return is(s1, s2, s3, 0, 0, 0);
    }
    bool is(string &s1, string &s2, string &s3, int i1, int i2, int i3) {
        if (i1 == s1.length())
            return s2.substr(i2) == s3.substr(i3);
        if (i2 == s2.length())
            return s1.substr(i1) == s3.substr(i3);
        if (s1[i1] == s3[i3] && s2[i2] == s3[i3])
            return is(s1, s2, s3, i1 + 1, i2, i3 + 1) || is(s1, s2, s3, i1, i2 + 1, i3 + 1);
        if (s1[i1] == s3[i3])
            return is(s1, s2, s3, i1 + 1, i2, i3 + 1);
        if (s2[i2] == s3[i3])
            return is(s1, s2, s3, i1, i2 + 1, i3 + 1);
        return false;
    }
};
