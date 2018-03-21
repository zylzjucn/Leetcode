class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, start = 0;
        int index[256];
        for (int i = 0; i < 256; i++) {
            index[i] = -1;
        }
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (index[c] != -1) {
                int newstart = index[c] + 1;
                for (int j = start; j < newstart; j++) 
                    index[s[j]] = -1;
                start = newstart;
            }
            index[c] = i;
            l = max(l, i - start + 1);
        }
        return l;
    }
};
