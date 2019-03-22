class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, start = 0, size = 0;
        int freq[256] = {0};
        for (int i = 0; i<s.length(); i++) {
            char c = s[i];
            if (freq[c] > 0)
                freq[c] ++;
            else {
                freq[c] = 1;
                size ++;
                while (size == k + 1) {
                    freq[s[start]]--;
                    if (freq[s[start]] == 0)
                        size--;
                    start++;
                }
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};
