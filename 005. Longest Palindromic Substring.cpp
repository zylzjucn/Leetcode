class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0)
            return "";
        if(s.length() == 1)
            return s;
        int maxstart = 0, maxlen = 1, i = 0, j, k, len;
        while(i < s.length()) {
            j = i;
            k = i;
            if(maxlen / 2 > s.length() - i)
                break;
            for(; k < s.length() - 1 && s[k] == s[k + 1]; k++);
            i = k + 1;
            for(; j > 0 && k < s.length() - 1 && s[j - 1] == s[k + 1]; j--, k++);
            len = k - j + 1;
            if(len > maxlen) {
                maxlen = len;
                maxstart = j;
            }
        }
        return s.substr(maxstart, maxlen);
    }
};
