class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, count = 0;
        int freqS[256] = {0};
        int freqT[256] = {0};
        string res;
        for (int i = 0; i < t.length(); i ++)
            freqT[t[i]] ++;
        for (int i = 0; i < s.length(); i ++) {
            if (freqT[s[i]] > 0) {
                if (freqS[s[i]] < freqT[s[i]])
                    count ++;
                freqS[s[i]] ++;
                if (count == t.length()) {
                    while (freqT[s[start]] == 0 || freqS[s[start]] > freqT[s[start]]) {
                        freqS[s[start]] --;
                        start ++;
                    }
                    if (res.length() == 0 || res.length() > i - start + 1)
                        res = s.substr(start, i - start + 1);
                }
            }
        }
        return res;
    }
};
