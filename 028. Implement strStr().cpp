class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        while((i < haystack.length()) && (j < needle.length())) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
        }
        return j == needle.length() ? i - j : -1;
    }
};
