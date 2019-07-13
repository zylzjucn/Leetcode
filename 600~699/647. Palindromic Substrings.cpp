class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            extend(s, i, i, res);
            extend(s, i, i + 1, res);
        }
        return res;
    }
    
    void extend(string& s, int start, int end, int& res) {
        while (start >= 0 && end < s.length() && s[start--] == s[end++])
            res++;
    };
};
