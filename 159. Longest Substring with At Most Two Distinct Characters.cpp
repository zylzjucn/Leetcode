class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length() == 1)
            return 1;
        int start1 = 0, start2 = 0, res = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[start1 - 1])
                start1 = i;
            else if (s[i] != s[i-1] && (i == 1 || s[i] != s[start1 - 1])) {
                start2 = start1;
                start1 = i;
            }
            res = max(res, i - start2 + 1);
        }
        return res;
    }
};
