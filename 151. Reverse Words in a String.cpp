class Solution {
public:
    void reverseWords(string &s) {
        int start = 0, i;
        for (i = 0; s[i] == ' '; i ++);
        s = s.substr(i, s.length() - i);  // delete the leading spaces
        rev (s, 0, s.length() - 1);  // reverse all
        for(i = 0; s[i] == ' '; i ++);
        s = s.substr(i, s.length() - i);  // delete the trailing spaces
        for (i = 1; i < s.length(); i ++) {
            if(s[i] == ' ') {
                if(s[i-1] != ' '){
                    rev(s, start, i-1);
                    start = i + 1;  // where the word begins
                }
                else {
                    s = s.substr(0, i) + s.substr(i + 1, s.length() - i);
                    i --;
                }
            } 
        }
        rev(s, start, s.length() - 1);
    }
    void rev(string &s, int start, int end)  // &
    {
        for(; start < end; start++, end--)
            swap(s[start], s[end]);
    }
};
