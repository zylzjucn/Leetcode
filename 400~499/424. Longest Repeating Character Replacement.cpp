class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int count[26] = {0};
        int start = 0;
        int maxCount = 0;
        for (int end = 0; end < s.length(); end++) {
            maxCount = max(maxCount, ++count[s[end] - 'A']);
            while (end - start + 1 > maxCount + k) {
                count[s[start] - 'A']--;
                start++;
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};
