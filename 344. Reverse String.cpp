class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.length() - 1;
        for(; i < j; i++, j--)
            swap(s[i], s[j]);
        return s;
    }
};
