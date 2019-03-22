class Solution {
public:
    int countBinarySubstrings(string s) {
        int c = 1, p = 0, r = 0, i = 1;
        for(; i < s.length(); i++) {
            if(s[i] == s[i - 1])
                c++;
            else {
                p = c;
                c = 1;
            }
            if (p >= c)
                r++;
        }
        return r;
    }
};
