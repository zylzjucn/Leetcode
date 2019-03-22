class Solution {
public:
    string reverseWords(string s) {
        int start = 0, i = 0; // i should be declared here due to the line 11
        for (; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        reverse(s, start, i - 1);
        return s;
    }
    void reverse(string &s, int start, int end) {  // & to save the change
        while (start < end)
            swap(s[start++], s[end--]);
    }
};
